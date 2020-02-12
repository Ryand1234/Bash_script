import sys
length = len(sys.argv)
email = str(sys.argv[1])
password = str(sys.argv[2])
import MySQLdb

db = MySQLdb.connect(host="localhost",   
                     user="root",        
                     passwd="riyan1234",  
                     db="data")        
cur = db.cursor()
query = "DELETE FROM form WHERE Name = %s and Password = %s"
arg = (email,password)
cur.execute(query,arg)
db.commit()
'''for row in cur.fetchall():
    for i in range(0,4):
    	print (str(row[i])+ " ")
'''
db.close()