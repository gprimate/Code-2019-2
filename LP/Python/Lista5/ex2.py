class Data:
    def __init__(self, day, month, year):
        validDate = False

        if type(day) is not int or type(month) is not int or type(year) is not int:
            raise Exception('Invalid Date')

        if day >= 1 and day <= 31 and month >= 1 and month <= 12 and year != 0 and not error:
            
            if month==2:
                bool29 = 0

                if  (year % 100 != 0 and year % 4 == 0) or  year % 400 == 0:
                    bool29 = 1

                if day <= (28 + bool29):
                    validDate = True

            elif month==4 or month==6 or month==9 or month==11:
                if day <=30:
                    validDate = True

            else:
                validDate = True
                
        if validDate:
            self.day = day
            self.month = month
            self.year = year
        else:
            raise Exception('Invalid Date')
        

