from flask import Flask,request,render_template
from subprocess import Popen,call,check_output
from os import fork,wait
app = Flask(__name__)
@app.route('/')
def home():
	return render_template("home.html")
@app.route('/',methods=['POST','GET'])
def detail():
	if request.method == 'POST':
		name = request.form['name']
		mob = request.form['number']
		email = request.form['email']
		message = request.form['complain']
		bank = request.form['bank']
		if message == "":
			return render_template("merror.html")
		child = fork()
		if child == 0:
			k = check_output(["sudo ","python3"," strip_complain,py",complain])
			return render_template("complaining.html")
		else:
			wait()
			Popen("sudo "," python3 "," to_database.py",name,mob,email,k,bank,complain," &")
			return render_template("complain_filed.html")
if __name__ == "__main__":
	app.run(debug=True,host="localhost")