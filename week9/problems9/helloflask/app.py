from flask import Flask, render_template, request

app = Flask(__name__)

valid_colors = ["blue", "red"]

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        return render_template("index.html")
    else:
        print("Form submitted!")
        color = request.form.get("color")
        if color not in valid_colors:
            return render_template("color.html", color="white")
        return render_template("color.html", color=color)
