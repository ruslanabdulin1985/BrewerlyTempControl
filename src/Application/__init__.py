from flask import Flask, render_template
from programs import Program1
import datetime

app = Flask(__name__)

@app.route("/")
def hello():

    return render_template('index.html')

@app.route("/program1")
def prgr1():
    return render_template('Program1.html', periods = Program1.periods, datetime=datetime.datetime)

if __name__ == "__main__":
    app.run(debug=True)