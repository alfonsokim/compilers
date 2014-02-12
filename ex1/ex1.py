import sys

# s = NUMERO + NUMERO

NUMEROS = '1234567890'

def valida_cadena_completa(cadena):
    for c in cadena:
        if c not in '1234567890+ ':
            error("cadena invalida")

def parsea_nums(cadena, tipo):
    current = 0
    nums = []
    signo = False
    numero = True
    for count, c in enumerate(cadena):
        #valida(c)
        if c in NUMEROS:
            nums.append(tipo(c))
        elif c in '+':
            pass
            #if signo:
            #    error("dos operadores + juntos")
            #signo = False
            #numero = False
        elif c in ' ':
            pass
            #if numero:
            #    error("dos numeros sin operador")
        else:
            error("caracter invalido: %s" % c)
    return nums


def tokens(cadena):
    return cadena.replace(' ', '').split('+')

def is_num(token):
    try:
        int(token)
        return True
    except:
        return False


def interprete(cadena):
    suma = 0
    for token in tokens(cadena):
        if is_num(token):
            suma += int(token)
        else:
            error("invalido: [%s]" % token)
    print suma


def compilador(cadena):
    programa = '''
#include <stdio.h>

void main(void){
    int resultado = %s;
    printf("%%d", resultado)
}
    '''
    nums = []
    for token in tokens(cadena):
        if is_num(token):
            nums.append(token)
        else:
            error("invalido: [%s]" % token)
    print programa % '+'.join(nums)


def error(mensaje="ex1.py <opcion> <cadena>"):
    print mensaje
    sys.exit(-1)


# =============================================
if len(sys.argv) != 3:
    error()

valida_cadena_completa(sys.argv[2])

if sys.argv[1] == '-i':
    interprete(sys.argv[2])
elif sys.argv[1] == '-c':
    compilador(sys.argv[2])
else:
    error()
