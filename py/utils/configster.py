import ConfigParser

class Configster:
    config_map = {}
    config = None
    
    def __init__(self, section):
        self.config = ConfigParser.ConfigParser()
        self.config.read("../../utils/config.ini")

        dict1 = {}
        options = self.config.options(section)
        for option in options:
            try:
                dict1[option] = self.config.get(section, option)
                if dict1[option] == -1:
                    DebugPrint("skip: %s" % option)
            except:
                print("exception on %s!" % option)
                dict1[option] = None
        self.config_map = dict1

    def get(self, key):
        return self.config_map[key]