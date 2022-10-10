from os import environ                                          
from flask import Flask, redirect, render_template, request, url_for, jsonify
from flask_cors import CORS, cross_origin
import requests
import json
import datetime
import instaloader
L = instaloader.Instaloader()

def getUserData(route):
    if request.headers.getlist("X-Forwarded-For"):
        ip = request.headers.getlist("X-Forwarded-For")[0]
    else:
        ip = request.remote_addr
    with open("users.txt", "a") as f:
        f.write(f"Page Visited: {route}\n")
        f.write(f"User Agent: {request.headers.get('User-Agent')}\n")
        f.write(f"Remote Addr: {ip}\n")
        f.write(f"DateTime: {datetime.datetime.now()}\n")
        f.write(f"\n\n\n")


def getProfile(username):
    profile = instaloader.Profile.from_username(L.context, username)
    print(profile.profile_pic_url)
    # for post in profile.get_posts():
    #     print("Imaege URL",post.url)
    #     print("Likes Count",post.likes)
    

    # Map profile.get_posts() to a list of dictionaries
    posts = [{
        'url': post.url,
        'shortcode': post.shortcode,
        'mediaid': post.mediaid,
        'caption': post.caption,
        'caption_hashtags': post.caption_hashtags,
        'caption_mentions': post.caption_mentions,
        'date': post.date_local,
        'typename': post.typename,
        'likes': post.likes,
        'comments': post.comments,
    } for post in profile.get_posts()]

    # return json.dumps(posts)

    userprofile = {
        "username": profile.username,
        "full_name": profile.full_name,
        "profile_pic_url": profile.profile_pic_url,
        "biography": profile.biography,
        "external_url": profile.external_url,
        "followers": profile.followers,
        "follows": profile.followees,
        "posts": posts,
        "is_private": profile.is_private,
        "is_verified": profile.is_verified,
    }
    return userprofile

app = Flask(__name__)
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'
app.debug = True
app.port = 8000

# 404 Handling
@app.errorhandler(404)
def not_found(e):
    getUserData("404 Page")
    return render_template("pages/404.html")

# Website
@app.route('/')
def index():
    getUserData("Index Page")
    return render_template('index.html')


@app.route('/testapi')
@cross_origin()
def testapi():
    getUserData("Test API")
    username = request.args.get('username')
    print("Username",username)
    # return "HIiii"
    
    response = jsonify({'profile': getProfile(username)})
    response.headers.add('Access-Control-Allow-Origin', '*')
    return response

@app.route('/getuser')
@cross_origin()
def testapi():
    getUserData("Test API")
    username = request.args.get('username')
    print("Username",username)
    # return "HIiii"
    
    response = jsonify({'profile': getProfile(username)})
    response.headers.add('Access-Control-Allow-Origin', '*')
    return response

    
if __name__ == '__main__':
    app.run()
