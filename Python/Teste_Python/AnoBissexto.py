class AnoBissexto:
    def is_ano_bissexto(self, ano):
        if ano % 400 == 0:
            return True
        elif ano % 4 == 0 and ano % 100 != 0:
            return True
        else:
            return False