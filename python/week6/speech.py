import pyttsx3

engine = pyttsx3.init()
inp = input("What is your name? ")
engine.say(f"hello, {inp}")            # Formatted strings work on ANY function that takes strings as a parameter
engine.runAndWait()
