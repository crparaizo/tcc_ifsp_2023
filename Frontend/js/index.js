

// var largura_janela = window.innerWidth;
// var altura_janela = window.innerHeight;

// canvas.width = window.largura_janela;
// canvas.height = window.altura_janela;

// canvas.style.background = "#ccc";


//contexto.stroke(); //linha do gráfico

//Espera elemento canvas renderizar para depois executar o script
document.addEventListener('DOMContentLoaded', domloaded, false);
function domloaded() {

    //Configurações do canvas
    var canvas = document.getElementById("senoide");
    var contexto = canvas.getContext("2d");
    contexto.beginPath();
    contexto.moveTo(0, 0);//ponto inicial
    //próximos pontos
    contexto.lineTo(355, 55);
    contexto.lineTo(355, 125);
    contexto.lineTo(25, 125);
    contexto.moveTo(465, 25);
    contexto.fill(); //preenchimento do gráfico
    //contexto.stroke(); //linha do gráfico


    var canvas2 = document.getElementById("quadrada");
    var ctx = canvas2.getContext("2d");

    ctx.fillStyle = "red";
    ctx.fillRect(20, 20, 75, 50);
    //Turn transparency on
    ctx.globalAlpha = 0.2;
    ctx.fillStyle = "blue";
    ctx.fillRect(50, 50, 75, 50);
    ctx.fillStyle = "green";
    ctx.fillRect(80, 80, 75, 50);

    function DrawGrid() {
        var canvas = document.getElementById("triangular");
        var context = canvas.getContext("2d");

        //var LineStartX = CenterX - (width / 2);
        // var LineStartY = CenterY - (height / 2);

        context.beginPath();
        context.moveTo(10, 20);
        context.lineTo(100, 20);
        context.strokeStyle = "blue";
        context.lineWidth = 1;
        context.stroke();
    }

    DrawGrid();
}