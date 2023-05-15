window.onload = function () {

    //definições iniciais para o gráfico
    var canvas = document.getElementById("canvasGrafico");
    if (canvas) {

        var altura = 500;  //altura da canvas        
        var largura = 700; //largura da canvas        
        var deslocHorizontal = 0; //posição horizontal inicial do gráfico        
        var valorEP32; //valor dos pontos do gráfico, que será lido do ESP32
        var zeroGrafico = 20 //determina o 0 do gráfico, para melhorar vizualição do usuário

        //formatando a canvas
        canvas.setAttribute("width", largura);
        canvas.setAttribute("height", altura);

        //obtendo o contexto 2d
        var ctx = canvas.getContext("2d");

        ctx.fillStyle = "lime";
        ctx.fillRect(0, 0, largura, altura);
        ctx.font = "30px Courier";
    }

    // atualizar valores a cada 500s     
    setInterval(function () {
        pegarValores();
        pegarTexto();
    }, 100);

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

        if ((pegouValores == true) && (pegouTexto == true)) {

            //caso deslocamento do eixo horizontal for maior que a largura do grafico, eixo volta para posição 0   ~/
            if (deslocHorizontal >= largura) {

                //onde começa x, onde termina y, tamanho dele (largura e altura): 
                ctx.clearRect(0, 0, 5, altura); //apagar iniciao do grafico
                ctx.fillStyle = "lime";
                ctx.fillRect(0, 0, 5, altura); //reconstruir inicio do grafico
                deslocHorizontal = 0; //deslocamento horizontal vou para inicio do grafico

                ctx.beginPath();
            }

            for (let valorJson in json) {
                
                //exibe valores no Console do navegador - para debug
                //console.log(valorJson + ": " + json[valorJson] / 10);

                ctx.clearRect(0, 0, deslocHorizontal + 5, altura);
                ctx.fillStyle = "lime";
                ctx.fillRect(0, 0, deslocHorizontal + 5, altura);   

                deslocHorizontal += 5; //deslocamento na horizontal            
                valorEP32 = json[valorJson] / 10; //valor lido do ESP32  
                ctx.lineTo(deslocHorizontal, altura - valorEP32 - zeroGrafico); //desenha uma linha até a posição gerada
                ctx.stroke();
                //desenha um retangulo onde está sendo escrito o valor do gráfico
                ctx.fillStyle = "lime";
                ctx.fillRect(0, 0, largura, 30);
                //desenha o texto indicando o valor do gráfico, na posição horizontal atual
                ctx.fillStyle = "red";
                ctx.fillText(valorEP32, deslocHorizontal, 30);

            }
        }

        pegouValores = false;
        pegouTexto = false;

    }
};