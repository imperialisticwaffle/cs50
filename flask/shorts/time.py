from flask import Flask
from datetime import datetime
from pytz import timezone

app = Flask(__name__)

@app.route("/")
def time():
    now = datetime.now(timezone('America/New York'))
    return "The current date and time in Cambridge is {}".format(now)

# We can pass parameters in using html syntax as well
@app.route("/show/<number>")
def show(number):
    return "You passed in {}".format(number)

# Forms only accept "POST" methods.
# There are a few functions helpful for application development
url_for()
redirect()
session()
render_template()