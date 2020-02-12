
from os import fork,system
from flask import Flask,render_template,request
from subprocess import call,Popen
app = Flask(__name__)
@app.route('/home/')
def home():
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
			Popen(['python3', 'log.py',email,password])
			return render_template("login.html")
@app.route('/home/delete/')
def dele():
	return render_template('delete.html',methods=["POST"])
def delet():
	name = request.form['name']
	email = request.form['email']
	passwd = request.form['password']
	frk = fork()
	if frk == 0:
		Popen(['sudo','python3', 'delete.py',name,email,password])
		return render_template("loadingdel.html")
	else:
		return render_template("delete.html")
@app.route('/home/about/')
def about():
	return render_template("loadingins.html")
if __name__=="__main__":
	app.run(host="localhost")