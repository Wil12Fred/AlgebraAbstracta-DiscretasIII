ZZ CMetodos::NumeroAleatorio(int bits)
{
    int tamano_semilla = 4;
    vector<bool> numero_binario = Semilla(tamano_semilla);

    for(int i = 0; i < bits - tamano_semilla; i++)
        numero_binario.push_back(Modulo(numero_binario[numero_binario.size() - 1] + numero_binario[numero_binario.size() - 2] + 1, 2));

    //RECORRIENDO BLOQUES
        int tamano_bloques = (bits * 25) / 100;

        for(int i = 0; i < numero_binario.size(); i += tamano_bloques)
        {
            //CORRIMIENTO HACIA LA DERECHA
                bool bit_fuera = numero_binario[i + (tamano_bloques - 1)];

                for(int j = 0; j < tamano_bloques - 1; j++)
                    numero_binario[(i + (tamano_bloques - 1)) - j] = numero_binario[((i + (tamano_bloques - 1)) - j) - 1];

                numero_binario[i] = Modulo(numero_binario[i + Modulo(rand(), tamano_bloques)] +
                                    numero_binario[i + Modulo(rand(), tamano_bloques)] +
                                    numero_binario[i + Modulo(rand(), tamano_bloques)] +
                                    bit_fuera, 2);

            //INTERCAMBIO ALEATORIO
                bool comodin = numero_binario[i];
                int posicion_aleatoria = i + Modulo(rand(), tamano_bloques);
                numero_binario[i] = numero_binario[posicion_aleatoria];
                numero_binario[posicion_aleatoria] = comodin;

            //CORRIMIENTO HACIA LA IZQUIERDA
                bit_fuera = numero_binario[i];

                for(int j = 0; j < tamano_bloques - 1; j++)
                    numero_binario[i + j] = numero_binario[(i + j) + 1];

                numero_binario[i + (tamano_bloques - 1)] = bit_fuera;
        }

    //BASE 2 A BASE 10
        ZZ numero = to_ZZ(1), exponenciacion_actual = to_ZZ(1);

        for(int i = 0; i < bits - 1; i++)
        {
            exponenciacion_actual = exponenciacion_actual << 1;
            if(numero_binario[i]) numero += exponenciacion_actual;
        }

    return numero;
}
