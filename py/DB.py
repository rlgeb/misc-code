# #!/usr/bin/python
print "Content-type:text/html\n\n"
import MySQLdb


class DB:
 
 conn = None #database connection
  
 """
  connects to the database 
 """
 def __init__(self, dbName):
  try:
   self.conn = MySQLdb.connect (
    host = "*******************",
    user = "*********",
    passwd = "*************************************",
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
db = DB("d3_project")
print db.query("programming_languages").fetch_row()

"""
