import sys
from flask import Flask,render_template,request
length = len(sys.argv)
email = str(sys.argv[1])
password = str(sys.argv[2])
import MySQLdb
from subprocess import Popen,call
db = MySQLdb.connect(host="localhost",   
                     user="root",        
                     passwd="riyan1234",  
                     db="data")        
cur = db.cursor()
query = "SELECT COUNT(*) FROM form WHERE Name = %s and Password = %s"
arg = (email,password)
cur.execute(query,arg)
exist = cur.rowcount
db.commit()
if exist != 1:
	return render_template("login.html")
'''for row in cur.fetchall():
    for i in range(0,4):
    	print (str(row[i])+ " ")
'''
db.close()