from os import fork,system
from flask import Flask,render_template,request
from subprocess import call,Popen
app = Flask(__name__)
@app.route('/home/')
def index():
	return render_template("home.html")
@app.route('/home/',methods=['POST','GET'])
def login():
	if request.method == 'POST':
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
				Popen(['sudo','python3', 'log.py',email,password])
				return render_template("loging.html")
@app.route('/delete/')
def dele():
	return render_template('delete.html')
@app.route('/delete/',methods=['POST','GET'])
def delet():
	if request.method == 'POST':
		email = request.form['email']
		passwd = request.form['password']
		frk = fork()
		if frk == 0:
			Popen(['sudo','python3', 'delete.py',email,passwd])
			return render_template("loadingdel.html")
		else:
			return render_template("delete.html")
if __name__=="__main__":
	app.run(host="localhost")