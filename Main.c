nclude <stdio.h>

struct item{
        int code;
        char name[10];
        float price;

};

int main(int argc, char* argv[]){
        struct item art;
        FILE* file;
        file = fopen("data.bin","wb");
        int continuar;

        do{
                printf("Codigo: ");
                scanf("%d", &art.code);
                printf("Nombre: ");
                scanf("%s", art.name);
                printf("Precio: ");
                scanf("%f", &art.price);
                fwrite(&art, sizeof(struct item), 1, file);
                printf("Desea Continuar? [si=1]");
                scanf("%d", &continuar);
                if(!continuar){
                    break;
                }
        }while(1);
        fclose(file);
        return 0;

}
