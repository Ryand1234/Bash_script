
from os import fork,system
from flask import Flask,render_template,request
from subprocess import call,Popen
app = Flask(__name__)
@app.route('/')
def index():
	return render_template("home.html")
@app.route('/',methods=["POST"])
def val():
	if len(request.form) >3:
		name = request.form['name']
		number = request.form['number']
		email = request.form['email']
		contry = request.form['contry']
		password = request.form['password']
		frk = fork()
		if frk == 0:
			Popen(['sudo','python3', 'insert.py',name,number, email,contry,password])
			return render_template("loadingins.html")
		else:
			return render_template("insert.html")
	else:
		email = request.form['email']
		password = request.form['password']
		frk = fork()
		if frk == 0:
			return render_template("loging.html")
		else:
			Popen(['python3', 'log.py',name,number, email,contry])
			return render_template("login.html")
if __name__=="__main__":
	app.run(host="localhost")