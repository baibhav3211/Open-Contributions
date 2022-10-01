import instaloader
L = instaloader.Instaloader()
profile = instaloader.Profile.from_username(L.context, 'meinhoonharsh')
print(profile.profile_pic_url)
for post in profile.get_posts():
  print("Imaege URL",post.url)
  print("Likes Count",post.likes)