from flask import Flask, render_template, request

app = Flask(__name__)       # turns current file into webapp listening for browser requests

# Now have to tell flask what the routes are
@app.route("/")
def index():                # Default route is called index. Run programs on flask with $ flask run
    # return render_template("index.html")        # find file index.html, grab contents, and return to user
    # return render_template("index.html", name=request.args.get("name", ", whoever you are"))      # If you want to return name as a second variable (since the second variable can be whatever you want), it
                                                                                                    # can be the same as whatever is after the question mark (recall search?q=cats).
    # request library gives you access to HTML requests and any parameters that might have been in the url.
    return render_template("index.html")

# @app.route("/greet")
@app.route("/greet", methods=["POST"])      # Method must be specified if not default value of "get"

def greet():
    # return render_template("greet.html", name=request.args.get("name", ", whoever you are"))
    return render_template("greet.html", name=request.form.get("name", ", whoever you are"))        # changed args to form to support "post"