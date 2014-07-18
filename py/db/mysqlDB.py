# #!/usr/bin/python
print "Content-type:text/html\n\n"
import MySQLdb
import ConfigParser

class mysqlDB:
 
 conn = None #database connection
  
 """
  connects to the database 
 """
def __init__(self, dbName):
  configParser = ConfigParser.RawConfigParser()   
  configParser.read(r'../../utils/config.txt')
  mysql_host = config.get('MYSQL_HOST', None)
  mysql_user = config.get('MYSQL_USER', None)
  mysql_password = config.get('MYSQL_PASS', None) 

  try:
   self.conn = MySQLdb.connect (
    host = mysql_host,
    user = mysql_user,
    passwd = mysql_password,
    db = dbName)
 
  except MySQLdb.Error, e:
   print "Error %d: %s" % (e.args[0], e.args[1])
   sys.exit (1)

#   print "connected to the database!"

 """
   query table for columns with passed constrains
   returns result set from query
 """
 def query(self, table, columns = "*", constraints=None):
  queryString = "SELECT " + columns + " FROM " + table 
  if(constraints):
    queryString += " WHERE " + constraints

  self.conn.query(queryString)
  return self.conn.use_result()

  """
   close the database connection
  """
  def __exit__(self, type, value, traceback):
  	this.conn.close() 

""" 
Example useage
db = mysqlDB("d3_project")
print db.query("programming_languages").fetch_row()

"""
