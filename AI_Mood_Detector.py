s = input()

if any(wd in s for wd in ["happy", "joy", "smile"]):
    print('Happy Mood')
elif any(wd in s for wd in ["sad", "cry", "angry"]):
    print('Sad Mood')
else:
    print('Neutral Mood')