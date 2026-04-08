import unittest
from AnoBissexto import AnoBissexto

class BissextoTest(unittest.TestCase):
    def setUp(self):
        self.ano_bissexto = AnoBissexto()
    
    def teste_ano_divisivel_por_400(self):
        self.assertTrue(self.ano_bissexto.is_ano_bissexto(2000))
    def teste_ano_divisivel_por_4_mas_nao_por_100(self):
        self.assertTrue(self.ano_bissexto.is_ano_bissexto(2024))
    
    # Métodos que testam anos que não são bissextos
    def teste_ano_divisivel_por_100_mas_nao_por_400(self):
        self.assertFalse(self.ano_bissexto.is_ano_bissexto(1900))
    def test_ano_nao_divisivel_por_4(self):
        self.assertFalse(self.ano_bissexto.is_ano_bissexto(2023))