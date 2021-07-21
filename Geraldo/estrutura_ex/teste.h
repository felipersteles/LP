typedef struct _ponto_ {
    float x, y;
}ponto;

typedef struct _circulo_{
    float raio;
    ponto centro;
}circulo;

typedef struct _retangulo_{
    ponto inicio;
    float largura, altura;
}retangulo;
