//definições dos botões de mudar tempo/div
function aumentarFreq() {

    var tempo_ms = document.getElementById("valorFreq").value;

    if (tempo_ms == 10) tempo_ms = 20;
    else if (tempo_ms == 20) tempo_ms = 40;
    else if (tempo_ms == 40) tempo_ms = 100;
    else if (tempo_ms == 100) tempo_ms = 200;

    if (tempo_ms != 10) {
        document.getElementById("botaoAnteriorFreq").style.visibility = "visible";
    }
    if (tempo_ms == 200) {
        document.getElementById("botaoPosteriorFreq").style.visibility = "hidden";
    }
    document.getElementById("valorFreq").value = tempo_ms;
}

function diminuirFreq() {

    var tempo_ms = document.getElementById("valorFreq").value;

    if (tempo_ms == 20) tempo_ms = 10;
    else if (tempo_ms == 40) tempo_ms = 20;
    else if (tempo_ms == 100) tempo_ms = 40;
    else if (tempo_ms == 200) tempo_ms = 100;

    if (tempo_ms == 10) {
        document.getElementById("botaoAnteriorFreq").style.visibility = "hidden";
    }
    if (tempo_ms != 200) {
        document.getElementById("botaoPosteriorFreq").style.visibility = "visible";
    }
    document.getElementById("valorFreq").value = tempo_ms;
}
//---------------------------------------------------------------------------

//definições dos botões de mudar tensão/div
function aumentarAmp() {

    var tensao_volts = document.getElementById("valorAmp").value;

    if (tensao_volts == 2.5) tensao_volts = 5;
    else if (tensao_volts == 5) tensao_volts = 10;

    if (tensao_volts != 2.5) {
        document.getElementById("botaoAnteriorAmp").style.visibility = "visible";
    }
    if (tensao_volts == 10) {
        document.getElementById("botaoPosteriorAmp").style.visibility = "hidden";
    }
    document.getElementById("valorAmp").value = tensao_volts;

}

function diminuirAmp() {
    var tensao_volts = document.getElementById("valorAmp").value;

    if (tensao_volts == 5) tensao_volts = 2.5;
    else if (tensao_volts == 10) tensao_volts = 5;

    if (tensao_volts == 2.5) {
        document.getElementById("botaoAnteriorAmp").style.visibility = "hidden";
    }
    if (tensao_volts != 10) {
        document.getElementById("botaoPosteriorAmp").style.visibility = "visible";
    }
    document.getElementById("valorAmp").value = tensao_volts;
}

//---------------------------------------------------------------------------

//espera a página carregar no navegador para mostrar gráfico
window.onload = function () {

    //definições iniciais para o gráfico
    var canvas = document.getElementById("canvasGrafico");
    if (canvas) {

        var altura = 500;  //altura da canvas        
        var largura = 700; //largura da canvas        
        var deslocHorizontal = 0; //posição horizontal inicial do gráfico        
        var valorEP32; //valor dos pontos do gráfico, que será lido do ESP32
        var zeroGrafico = 20 //determina o 0 do gráfico, para melhorar vizualição do usuário

        var voltagem;

        //formatando a canvas
        canvas.setAttribute("width", largura);
        canvas.setAttribute("height", altura);

        //obtendo o contexto 2d
        var ctx = canvas.getContext("2d");
        ctx.lineWidth = 3;

        ctx.fillStyle = "white";
        ctx.fillRect(0, 0, largura, altura);
        ctx.font = "30px Courier";
    }

    //variavel que controla amplitude do grafico
    var fatorDivisao = 1;


    // atualizar valores a cada 500s     
    setInterval(function () {
        pegarValores();
        pegarTexto();
    }, 500);

    //criando sincronismo entre as funções
    var pegouValores = false;
    var pegouTexto = false;

    //função feita com AJAX que atualiza Placeholder sem atualizar a página
    //Formato é HTML
    function pegarValores() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
            //se chamada ajax foi concluida (4) e status for ok (200)
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("placeholder").innerHTML = this.responseText;
                //alert(JSON.parse(this.responseText));
                pegouValores = true;
            }
        };
        xhttp.open("GET", "index.html", true);
        xhttp.send();
    }

    //função feita com AJAX que pegar texto do Placeholder
    //Formato é "Plain text"
    function pegarTexto() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
            //se chamada ajax foi concluida (4) e status for ok (200)
            if (this.readyState == 4 && this.status == 200) {
                var vetor = document.getElementById("placeholder")
                vetor = this.responseText;
                var json = JSON.parse(vetor);

                pegouTexto = true;

                desenharGrafico(json);
            }
        };

        xhttp.open("GET", "texto", true);
        xhttp.send();
    }


    //função desenharGrafico
    function desenharGrafico(json) {

        //condições a depender do tempo/div escolhido:
        //--------------------------------------------

        var valorTempo = document.getElementById("valorFreq").value;
        var larguraAlterada = 0; //altera distancia entre pontos -> eixo X


        if (valorTempo == 10) {
            larguraAlterada = 10;

        } else if (valorTempo == 20) {
            larguraAlterada = 20;

        } else if (valorTempo == 40) {
            larguraAlterada = 0;

        } else if (valorTempo == 100) {
            larguraAlterada = 100;

        } else if (valorTempo == 200) {
            larguraAlterada = 200;

        } else {
            larguraAlterada = 0;
        }

        //--------------------------------------------

        //condições a depender do tensao/div escolhido:
        //--------------------------------------------
        var valorTensao = document.getElementById("valorAmp").value;
        //var alturaAlterada = 0; //altera altura da onda -> eixo Y 

        if (valorTensao == 2.5) {
            fatorDivisao = 4;

        } else if (valorTensao == 5) {
            fatorDivisao = 2;

        } else if (valorTensao == 10) {
            fatorDivisao = 1;
        }

        //--------------------------------------------

        if ((pegouValores == true) && (pegouTexto == true)) {

            //caso deslocamento do eixo horizontal for maior que a largura do grafico, eixo volta para posição 0   ~/
            if (deslocHorizontal >= largura) {

                //onde começa x, onde termina y, tamanho dele (largura e altura): 
                ctx.clearRect(0, 0, 5, altura); //apagar iniciao do grafico
                ctx.fillStyle = "white";
                ctx.fillRect(0, 0, 5, altura); //reconstruir inicio do grafico
                deslocHorizontal = 0; //deslocamento horizontal vou para inicio do grafico

                ctx.beginPath();
            }

            for (let valorJson in json) {

                //exibe valores no Console do navegador - para debug
                //console.log(valorJson + ": " + json[valorJson] / 10);

                ctx.clearRect(0, 0, deslocHorizontal + 5, altura);
                ctx.fillStyle = "white";
                ctx.fillRect(0, 0, deslocHorizontal + 5, altura);

                //medicaoReal = - (valorMedido * (20 / 3) - 10);
                //voltagem = - ((json[valorJson] * (3.3 / 4095)) * (20 / 3) - 10);

                //voltagem = json[valorJson] * (10 / 4095);
                //voltagem = json[valorJson] * (3.3 / 4095);
                parsedValue = parseFloat(voltagem);
                result = parsedValue.toFixed(2);
                //console.log(valorJson + ": " + result);

                deslocHorizontal += 5; //deslocamento na horizontal            
                valorEP32 = (json[valorJson] / 10) / fatorDivisao; //valor lido do ESP32  
                ctx.lineTo(deslocHorizontal, altura - valorEP32 - zeroGrafico); //desenha uma linha até a posição gerada
                ctx.strokeStyle = "magenta";
                ctx.stroke();
                //desenha um retangulo onde está sendo escrito o valor do gráfico
                ctx.fillStyle = "white";
                ctx.fillRect(0, 0, largura, 30);
                //desenha o texto indicando o valor do gráfico, na posição horizontal atual
                ctx.fillStyle = "red";
                ctx.fillText(result, deslocHorizontal, 30);
                //ctx.fillText(valorEP32, deslocHorizontal, 30);

            }
        }

        pegouValores = false;
        pegouTexto = false;

    }
};