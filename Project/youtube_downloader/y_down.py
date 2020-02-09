import urllib
from urllib import request ,error
from urllib.request import Request,urlopen
import webbrowser
from flask import Flask , request,render_template
from subprocess import call,Popen,check_call
from selenium import webdriver
app = Flask(__name__)

@app.route('/')
def index():
	return render_template('home.html')
@app.route('/',methods=['POST'])
def input():
	url = request.form['Link']
	req = Request(url)
	try:
		req1=urlopen(req)
	except (error,e):
		if hasattr(e,'reason'):
			return render_template('error.html',error=e.reason);
		elif hasattr(e,'code'):
			return render_template("error1.html",error=e.code)
	else:
		webbrowser.open(url)
		'''render_template('download_video.html',url=url)'''
		call(["bash download.sh "+url ],shell=True)
		return render_template('download_video.html',url=url)
		
	
if __name__=="__main__":
	app.run(host='localhost')