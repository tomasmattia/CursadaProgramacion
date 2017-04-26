typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;
} eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;

} eCliente;

typedef struct
{
    int idCliente;
    int idSerie;
} eClientes_Series;

typedef struct//Para el punto 5
{
    int idSerie;
    int cont;
} eLoser;

void cargarSeries(eSerie series[]);

void cargarClientes(eCliente clientes[]);

void cargarCliente_Serie(eClientes_Series clientesSeries[]);

void mostrarClientes(eCliente clientes[]);

void mostrarSeries(eSerie series[]);

void mostrarClientesConSeries(eCliente clientes[],eSerie series[],eClientes_Series clientesSeries[],int,int,int);

void mostrarSeriesConClientes(eCliente clientes[],eSerie series[],eClientes_Series clientesSeries[],int,int,int);

void mostrarSeriesUnCliente(eCliente clientes[],eSerie series[],eClientes_Series clientesSeries[],int,int,int);

void serieMenosPopular(eCliente clientes[],eSerie series[],eClientes_Series clientesSeries[],int,int,int);

