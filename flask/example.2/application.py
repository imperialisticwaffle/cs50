from flask import Flask, render_template, request

app = Flask(__name__)       # turns current file into webapp listening for browser requests

# Now have to tell flask what the routes are
@app.route("/", methods=["GET", "POST"]
def index():
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        return render_template("greet.html") name=request.form.get("name", ", whoever you are")