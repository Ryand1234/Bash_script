import sys
length = len(sys.argv)
name = str(sys.argv[1])
mobile = (sys.argv[2])
email = str(sys.argv[3])
contry = str(sys.argv[4])
password = str(sys.argv[5])
import MySQLdb

db = MySQLdb.connect(host="localhost",    # your host, usually localhost
                     user="root",         # your username
                     passwd="riyan1234",  # your password
                     db="data")        # name of the data base

# you must create a Cursor object. It will let
#  you execute all the queries you need
cur = db.cursor()

# Use all the SQL you like
query = "INSERT INTO form (Name,Number,Email,Address,Password) values (%s,%s,%s,%s,%s)"
arg = (name,mobile,email,contry,password)
cur.execute(query,arg)
db.commit()
# print all the first cell of all the rows
'''for row in cur.fetchall():
    for i in range(0,4):
    	print (str(row[i])+ " ")
'''
db.close()