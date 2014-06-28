<?php

class DB { 
	
	public $dbName;
	private $conn = null;
	public static $serverName = '*********';	
	public static $username = '***********';
    public static $passwrd = '***********';

	/**
	 *  connects to the database
	 **/
	public function __construct($dbName)  {
		
		$this->conn = mysqli_connect(self::$serverName, self::$username, self::$passwrd, $dbName); 
		if (!$this->conn) { 
 			die('Could not connect: ' . mysql_error()); 
 		} 
//  		echo 'Connected successfully!'; 
	}
	
 	/**
	 *  querys table for columns in the database with constraints
	 **/
	public function query($table, $columns = "*", $constraints=null) {
		$queryString = 'SELECT ' . $columns . ' FROM ' . $table;
	  	if($constraints) {
	    	$queryString .= ' WHERE ' . $constraints;
		}
		
	  	return mysqli_query($this->conn, $queryString);
	}
	
	/**
	 *  closes the connection to the database
	 **/	
	public function __destruct() {
		mysql_close($this->conn);
	}
}


/*
// Example usage 

$db = new DB('d3_project');
$result = $db->query('programming_languages');
while($row = mysqli_fetch_array($result)) {
   var_dump($row);
}
*/
?>
