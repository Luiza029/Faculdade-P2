class Matematica:
    @staticmethod
    def fibonacci(n):
        if n == 0:
            return 0
        elif n == 1 or n == 2:
            return 1
        elif n > 2:
            return Matematica.fibonacci(n-1) + Matematica.fibonacci(n-2)