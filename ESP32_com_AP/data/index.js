

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
    var canvas = document.getElementById("grafico");
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


    var canvas2 = document.getElementById("grafico");
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
        var canvas = document.getElementById("grafico");
        var context = canvas.getContext("2d");

        //var LineStartX = CenterX - (width / 2);
        // var LineStartY = CenterY - (height / 2);

        context.beginPath();
        context.moveTo(10, 20);
        context.lineTo(100, 20);
        context.strokeStyle = "white";
        context.lineWidth = 1;
        context.stroke();
    }

    DrawGrid();
}

function botaoZmenos() {
    alert("botaoZmenos");
}

function botaoZmais() {
    alert("botaoZmais");
}

function botaoTRmenos() {
    alert("botaoTRmenos");
}

function botaoTRmais() {
    alert("botaoTRmais");
}

function botaoDiv() {
    alert("botaoDiv");
}

function botaoA0() {
    alert("botaoA0");
}

function botaoA1() {
    alert("botaoA1");
}

function botaoRising() {
    alert("botaoRising");
}

function botaoFailing() {
    alert("botaoFailing");
}

function botaoChange() {
    alert("botaoChange");
}