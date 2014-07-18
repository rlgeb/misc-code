import sys
sys.path.insert(0, '../')
import gdata.docs.data
import gdata.docs.client
import gdata.spreadsheet.service
from utils import configster

"""
gdocDB - quickly store data using a google doc spreadsheet

note:
Requires Google credentials to record results.
If your Google account has 2-factor authentication enabled, 
you may need to generate an application specific password.
"""
class gdocDB:
    google_client = None
    table_name = 'temp'
    table_key = None   
    google_client = None
    spread_sheet_service = None

    def __init__(self, appName):
        self.app_name = appName

        config = configster.Configster('google')
        user = config.get('google_account_user')
        password = config.get('google_account_pass')
        
        self.google_client = gdata.docs.client.DocsClient(source=self.app_name)
        self.google_client.client_login(user, password, source=self.app_name, service='writely')

        self.spread_sheet_service = gdata.spreadsheet.service.SpreadsheetsService()
        self.spread_sheet_service.ClientLogin(user, password)


    """
        input:  tableName - the name of the spreadsheet, columns - array of column names
        output: None
        desc:   sets up the cols in the spreadsheet
    """    
    def create_table(self, tableName, columns):
        self.table_name = tableName
        self.cols = columns
        document = gdata.docs.data.Resource(type='spreadsheet', title=self.table_name)
        document = self.google_client.CreateResource(document)
        self.table_key = document.GetId().split("%3A")[1]

        column_number = 1
        for col in self.cols:
            self.spread_sheet_service.UpdateCell(1, column_number, col, self.table_key)
            column_number = column_number + 1

        self.cols = columns


    """
        input:  data is a map for col to value
        output: None
        desc:   inserts a new row and fill it with data
    """    
    def insert(self, data):
        row = {}
        for col in self.cols:
            if data[col]:
                row[col] = data[col]
        self.spread_sheet_service.InsertRow(row, self.table_key)



# def example():
#     db = gdocDB('VolunteerSignup')
#     columns = ['name', 'phone', 'email']
#     db.create_table('example', columns)
    
#     data = {}
#     data['Name'] = 'Becca'
#     data['Phone'] = '+1 (313) 254-0020'
#     data['Email'] = 'me@example.com'
    
#     db.insert(data)

# example()
