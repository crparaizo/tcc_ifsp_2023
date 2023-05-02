window.onload = function () {

    //definições iniciais para o gráfico
    var canvas = document.getElementById("canvasGrafico");
    if (canvas) {

        var altura = 420;  //altura da canvas        
        var largura = 700; //largura da canvas        
        var deslocHorizontal = 0; //posição horizontal inicial do gráfico        
        var valor; //valor dos pontos do gráfico, que será lido do ESP32

        //formatando a canvas
        canvas.setAttribute("width", largura);
        canvas.setAttribute("height", altura);

        //obtendo o contexto 2d
        var ctx = canvas.getContext("2d");

        ctx.fillStyle = "lime";
        ctx.fillRect(0, 0, largura, altura);
        ctx.font = "30px Courier";
    }

    // atualizar valores a cada 2s     
    setInterval(function () {
        pegarValores();
        pegarTexto();
    }, 2000);


    //função feita com AJAX que atualiza Placeholder sem atualizar a página
    //Formato é HTML
    function pegarValores() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
            //se chamada ajax foi concluida (4) e status for ok (200)
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("placeholder").innerHTML = this.responseText;
                //alert(JSON.parse(this.responseText));
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

                desenharGrafico(json);
            }
        };

        xhttp.open("GET", "texto", true);
        xhttp.send();
    }


    //função desenharGrafico
    function desenharGrafico(json) {

        for (let teste in json) {

            console.log(teste + ": " + json[teste] / 10);

            deslocHorizontal += 5; //deslocamento na horizontal            
            valor = json[teste] / 10; //valor lido do ESP32            
            ctx.lineTo(deslocHorizontal, altura - valor); //desenha uma linha até a posição gerada
            ctx.stroke();
            //desenha um retangulo onde está sendo escrito o valor do gráfico
            ctx.fillStyle = "lime";
            ctx.fillRect(0, 0, largura, 30);
            //desenha o texto indicando o valor do gráfico, na posição x atual
            ctx.fillStyle = "red";
            ctx.fillText(valor, deslocHorizontal, 30);
        }

        //acrescentar novas infos no grafico do começo
        /*
        if (deslocHorizontal >= largura) {
            deslocHorizontal = 0;
        }
        */
    }

};