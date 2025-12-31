from flask import Flask, render_template, request, redirect, session
from cs50 import SQL
from werkzeug.security import generate_password_hash, check_password_hash

app = Flask(__name__)
app.secret_key = "secret"

db = SQL("sqlite:///finance.db")

@app.route("/")
def index():
    if "user_id" not in session:
        return redirect("/login")
    return render_template("index.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form.get("username")
        password = generate_password_hash(request.form.get("password"))

        db.execute(
            "INSERT INTO users (username, hash) VALUES (?, ?)",
            username, password
        )
        return redirect("/login")

    return render_template("register.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")

        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        if len(rows) == 1 and check_password_hash(rows[0]["hash"], password):
            session["user_id"] = rows[0]["id"]
            return redirect("/")

    return render_template("login.html")

@app.route("/logout")
def logout():
    session.clear()
    return redirect("/login")