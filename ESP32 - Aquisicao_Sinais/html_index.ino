String html_index(String dado,int tempo)
{

  String conteudo; // variável que armazenará o script HTML

  conteudo = F(

"<!DOCTYPE html>\n" 
"<html lang=\"pt-br\">\n" 

"<head>\n" 
    "<meta charset=\"UTF-8\">\n" 
    "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n" 
    "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n" 
    "<title>ESP32</title>\n" 
"</head>\n" 

"<header>\n" 

    "<div class=\"logoIF\">\n" 
        "<h1>Instituto Federal de São Paulo</h1>\n" 
    "</div>\n" 

    "<nav class=\"menu\">\n" 
        "<div class=\"topnav\">\n" 
            "<a class=\"active\" href=\"http://192.168.4.1/\">Home</a>\n" 
            "<a href=\"http://192.168.4.1/sobre\">Sobre</a>\n" 
            "<a href=\"http://192.168.4.1/contato\">Contato</a>\n" 
        "</div>\n" 
    "</nav>\n" 

"</header>\n" 

"<body>\n" 

    "<div class=\"titulo\">\n" 
        "<h1>Sistema de Aquisição e Geração com ESP32</h1>\n" 
    "</div>\n" 

    "<!-- Limitações da tag canvas: alguns navegadores mais antigos"
        "(em particular, versões do Internet Explorer anteriores a 9)" 
        "não suportam o elemento -->"

    "<div class=\"main\">\n" 

        "<div class=\"grafico\">\n" 
            "<canvas id=\"grafico\">\n" 
                "<!-- Se seu navegador não suportar HTML5 você verá a mensagem abaixo -->"
                "Este navegor não suporta HTML5, não será possível visualizar esse gráfico"
            "</canvas>\n" 
            "<div id=\"fundo_grafico\"></div>\n" 
        "</div>\n" 

        "<div id=\"botoes\">\n" 
            "<div class=\"frequencia\">\n" 
                "<form id=\"formulario\" action=\"frequencia\" method=\"post\">\n" 
                    "Tempo/DIV (ms): <input class=\"tempo_div\" type=\"text\" name=\"tempoNovo\">\n" 
                    "<input type=\"submit\" value=\"Atualizar\">\n" 
                "</form>\n" 
            "</div>\n" 

            "<div class=\"acompanhamento\">\n" 
            );
         conteudo += F("<p>Tempo/DIV:");
         conteudo += tempo;
         conteudo += F("ms</p>\n");
  
         conteudo += F( 
            "</div>\n" 

            "<div class=\"amplitude\">\n" 
                "<p id=\"textoAmp\">Tensão/DIV (volts):</p>\n" 
                "<button id=\"botaoAnteriorAmp\" onclick=\"diminuirAmp()\">-</button>\n" 
                "<input class=\"tensao_div\" id=\"valorAmp\" value=\"10\">\n" 
                "<button id=\"botaoPosteriorAmp\" onclick=\"aumentarAmp()\">+</button>\n" 
            "</div>\n" 

       " </div>\n" 

    "</div>\n" 

"</body>\n" 

"<footer class=\"rodape\">\n" 
    "<p>Elaborado em 2023</p>\n" 
"</footer>\n" 

"</html>\n" 

"<style>\n" 
    /* customização aplicada a todos os elementos da página */

    "@charset \"UTF-8\";\n" 

    "* {\n" 
        "margin: 0;\n" 
        "padding: 0;\n" 
        "box-sizing: border-box;\n" 
        "font-family: \"open_sansbold\", 'Open Sans', Arial, Helvetica, sans-serif;\n" 
    "}\n" 

    /* customização do cabeçalho */
    "header {\n" 
        "display: flex;\n" 
        "justify-content: space-between;\n" 
        "align-items: center;\n" 
        "padding: 10px 0;\n" 
        "background-color: #17882c;\n" 
    "}\n" 

    ".logoIF {\n" 
        "width: 50%;\n" 
        "display: flex;\n" 
        "align-items: center;\n" 
        "justify-content: space-evenly;\n" 
        "color: white;\n" 
    "}\n" 

    ".menu {\n" 
        "width: 50%;\n" 
    "}\n" 

    ".topnav {\n" 
        "display: flex;\n" 
        "justify-content: space-around;\n" 
    "}\n" 

    ".topnav a {\n" 
        "color: white;\n" 
        "font-size: 18px;\n" 
        "text-decoration: none;\n" 
    "}\n" 

    ".topnav a:hover {\n" 
        "color: yellow;\n" 
        "text-decoration: underline;\n" 
    "}\n" 

    /* customização do corpo da página */

    ".titulo {\n" 
        "display: flex;\n" 
        "justify-content: center;\n" 
        "padding-top: 30px;\n" 
        "color: #2c66ce;\n" 
    "}\n" 

    /* gráfico que mostra o sinal gerado */

    ".grafico {\n" 
        "display: flex;\n" 
        "justify-content: center;\n" 
        "margin: 15px 0;\n" 
    "}\n" 

    "#grafico {\n" 
        "width: 1000px;\n" 
        "height: 500px;\n" 
        "border: 2px solid;\n" 
        "border-color: black;\n" 
    "}\n" 

    /* ---------------------------------------- */

    /* gráfico que simula os aspectos da tela do osciloscopio */

    "#fundo_grafico {\n" 
        "background-color: transparent;\n" 
        "z-index: 2;\n" 
        "position: absolute;\n" 

        "background: rgba(255, 255, 255, 0.5);\n" 
        "background-image: linear-gradient(rgba(198, 147, 147, 0.5) .5px, transparent 5px),\n" 
            "linear-gradient(90deg, rgba(198, 147, 147, 0.5) .5px, transparent 5px);\n" 
        "background-size: 50px 50px;\n" 
        /* --------------------------- */
        "width: 1000px;\n" 
        "height: 500px;\n" 
        /* --------------------------- */
    "}\n" 

    "#canvasGrafico {\n" 
        "z-index: 1;\n" 
        "position: absolute;\n" 
    "}\n" 

    "main {\n" 
        "display: flex;\n" 
        "flex-direction: row;\n" 
    "}\n" 

    "#formulario {\n" 
        "display: flex;\n" 
        "flex-direction: column;\n" 
        "text-align: center;\n" 
    "}\n" 

    "#botoes {\n" 
        "display: flex;\n" 
        "flex-direction: row;\n" 
        "text-align: center;\n" 
        "justify-content: space-around;\n" 
        "align-items: center;\n" 
    "}\n" 

    ".amplitude button {\n" 
        "height: 2em;\n" 
        "width: 2em;\n" 
    "}\n" 

    ".tempo_div,\n" 
    ".tensao_div {\n" 
        "border-radius: 50px;\n" 
        "text-align: center;\n" 
        "margin: 7px 0;\n" 
        "width: 200px;\n" 
        "height: 25px;\n" 
    "}\n" 

    /* ---------------------------------------- */

    /* customização do rodapé */

    ".rodape {\n" 
        "width: 100%;\n" 
        "display: flex;\n" 
        "justify-content: center;\n" 
        "align-items: center;\n" 
        "height: 50px;\n" 
        "background-color: #17882c;\n" 
        "color: white;\n" 
        "margin-top: 40px;\n" 
    "}\n" 

    /* Aplicando responsividade de acordo com tamanho da tela */

    "@media screen and (max-width: 1300px) {\n" 

        ".logoIF h1 {\n" 
            "font-size: 25px;\n" 
        "}\n" 
    "}\n" 

    "@media screen and (max-width: 1100px) {\n" 

        ".logoIF h1 {\n" 
            "font-size: 20px;\n" 
        "}\n" 

        "#grafico {\n" 
            "width: 800px;\n" 
        "}\n" 
    "}\n" 

    "@media screen and (max-width: 900px) {\n" 

        "#grafico {\n" 
            "width: 600px;\n" 
        "}\n" 
    "}\n" 

    "@media screen and (max-width: 800px) {\n" 

        ".logoIF h1 {\n" 
            "font-size: 15px;\n" 
        "}\n" 

        ".topnav a {\n" 
            "font-size: 13px;\n" 
        "}\n" 

        ".titulo h1 {\n" 
            "font-size: 25px;\n" 
        "}\n" 
    "}\n" 

    "@media screen and (max-width: 700px) {\n" 

        "#grafico {\n" 
            "width: 500px;\n" 
        "}\n" 
    "}\n" 

    "@media screen and (max-width: 600px) {\n" 

        ".titulo h1 {\n" 
            "font-size: 20px;\n" 
        "}\n" 

        ".logoIF {\n" 
            "width: 150%;\n" 
        "}\n" 

        ".menu {\n" 
            "width: 40%;\n" 
        "}\n" 

        ".topnav {\n" 
            "flex-direction: column;\n" 
            "justify-content: center;\n" 
            "align-items: center;\n" 
        "}\n" 

        ".topnav a {\n" 
            "font-size: 16px;\n" 
            "padding-bottom: 4px;\n" 
        "}\n" 

        "#grafico {\n" 
            "width: 400px;\n" 
        "}\n" 

        "@media screen and (max-width: 450px) {\n" 

            ".titulo h1 {\n" 
                "font-size: 15px;\n" 
            "}\n" 

            "#grafico {\n" 
                "width: 300px;\n" 
            "}\n" 
        "}\n" 

        "@media screen and (max-width: 415px) {\n" 

            ".titulo h1 {\n" 
                "text-align: center;\n" 
            "}\n" 

            "#grafico {\n" 
                "width: 250px;\n" 
            "}\n" 
        "}\n" 
    "}\n" 
"</style>\n" 

"<script>\n" 

    //definições dos botões de mudar tensão/div
    "function aumentarAmp() {\n" 
        "var tensao_volts = document.getElementById(\"valorAmp\").value;\n" 

        "if (tensao_volts == 2.5) tensao_volts = 5;\n" 
        "else if (tensao_volts == 5) tensao_volts = 10;\n" 

        "if (tensao_volts != 2.5) {\n" 
            "document.getElementById(\"botaoAnteriorAmp\").style.visibility = \"visible\";\n" 
        "}\n" 
        "if (tensao_volts == 10) {\n" 
            "document.getElementById(\"botaoPosteriorAmp\").style.visibility = \"hidden\";\n" 
        "}\n" 
        "document.getElementById(\"valorAmp\").value = tensao_volts;\n" 
    "}\n" 

    "function diminuirAmp() {\n" 
        "var tensao_volts = document.getElementById(\"valorAmp\").value;\n" 

        "if (tensao_volts == 5) tensao_volts = 2.5;\n" 
        "else if (tensao_volts == 10) tensao_volts = 5;\n" 

        "if (tensao_volts == 2.5) {\n" 
            "document.getElementById(\"botaoAnteriorAmp\").style.visibility = \"hidden\";\n" 
        "}\n" 
        "if (tensao_volts != 10) {\n" 
            "document.getElementById(\"botaoPosteriorAmp\").style.visibility = \"visible\";\n" 
        "}\n" 
        "document.getElementById(\"valorAmp\").value = tensao_volts;\n" 
    "}\n" 

    //Espera elemento canvas renderizar para depois executar o script
    "window.onload = function () {\n" 

        //definições iniciais para o gráfico
        "var canvas = document.getElementById(\"grafico\");\n" 
        "if (canvas) {\n" 

            "var altura = canvas.offsetHeight;  //altura da canvas\n"         
            "var largura = canvas.offsetWidth; //largura da canvas\n"         
            "var deslocHorizontal = 0; //posição horizontal inicial do gráfico\n"
            "var valorEP32; //valor dos pontos do gráfico, que será lido do ESP32\n"
            "var zeroGrafico = 20; //determina o 0 do gráfico, para melhorar vizualição do usuário\n" 
            "var voltagem;\n" 

            //formatando a canvas
            "canvas.setAttribute(\"width\", largura);\n" 
            "canvas.setAttribute(\"height\", altura);\n" 

            //obtendo o contexto 2d
            "var ctx = canvas.getContext(\"2d\");\n" 
            "ctx.lineWidth = 4;\n" 

            "ctx.fillStyle = \"white\";\n" 
            "ctx.fillRect(0, 0, largura, altura);\n" 
            "ctx.font = \"bold 30px Courier\";\n" 
        "}\n" 

        //variavel que controla amplitude do grafico
        "var fatorDivisao = 1;\n" 

        // atualizar valores a cada 50ms     
        "setInterval(function () {\n" 
            "pegarTexto();\n" 
        "}, 10);\n" 

        //criando sincronismo entre as funções
        "var pegouTexto = false;\n" 

        //função feita com AJAX que pegar texto do Placeholder
        //Formato é "Plain text"
        "function pegarTexto() {\n" 
            "var xhttp = new XMLHttpRequest();\n" 
            "xhttp.onreadystatechange = function () {\n" 
                //se chamada ajax foi concluida (4) e status for ok (200)
                "if (this.readyState == 4 && this.status == 200) {\n" 
                    "var vetor = document.getElementById(\"placeholder\")\n" 
                    "vetor = this.responseText;\n" 
                    "var json = JSON.parse(vetor);\n" 
                    "pegouTexto = true;\n" 
                    "desenharGrafico(json);\n" 
                "}\n" 
            "};\n" 
            "xhttp.open(\"GET\", \"texto\", true);\n" 
            "xhttp.send();\n" 
        "}\n" 

        //função desenharGrafico
        "function desenharGrafico(json) {\n" 

            //condições a depender do tensao/div escolhido:
            "var valorTensao = document.getElementById(\"valorAmp\").value;\n" 

            "if (valorTensao == 2.5) {\n" 
                "fatorDivisao = 4;\n" 

            "} else if (valorTensao == 5) {\n" 
                "fatorDivisao = 2;\n" 

            "} else if (valorTensao == 10) {\n" 
                "fatorDivisao = 1;\n" 
            "}\n" 

            "if ((pegouTexto == true)) {\n" 

                //caso deslocamento do eixo horizontal for maior que a largura do grafico, eixo volta para posição 0   ~/
                "if (deslocHorizontal >= largura) {\n" 

                    //onde começa x, onde termina y, tamanho dele (largura e altura): 
                    "ctx.clearRect(0, 0, 1, altura); //apagar iniciao do grafico\n" 
                    "ctx.fillStyle = \"white\";\n" 
                    "ctx.fillRect(0, 0, 1, altura); //reconstruir inicio do grafico\n" 
                    "deslocHorizontal = 0; //deslocamento horizontal vou para inicio do grafico\n" 

                    "ctx.beginPath();\n" 
                "}\n" 

                "for (let valorJson in json) {\n" 

                    //exibe valores no Console do navegador - para debug

                    "ctx.clearRect(0, 0, deslocHorizontal + 1, altura);\n" 
                    "ctx.fillStyle = \"white\";\n" 
                    "ctx.fillRect(0, 0, deslocHorizontal + 1, altura);\n" 

                    "voltagem = - ((json[valorJson] * (3.3 / 4095)) * (20 / 3) - 10) / fatorDivisao;\n" 
                    "parsedValue = parseFloat(voltagem);\n" 
                    "resultado = parsedValue.toFixed(2);\n" 
                    //console.log(resultado);

                    "deslocHorizontal += 1; //deslocamento na horizontal\n" 
                    "valorEP32 = (json[valorJson] / 10) / fatorDivisao; //valor lido do ESP32\n"                           
                    "ctx.lineTo(deslocHorizontal, altura - valorEP32 - zeroGrafico); //desenha uma linha até a posição gerada\n" 
                    "ctx.strokeStyle = \"magenta\";\n" 
                    "ctx.stroke();\n" 
                    //desenha um retangulo onde está sendo escrito o valor do gráfico
                    "ctx.fillStyle = \"white\";\n" 
                    "ctx.fillRect(0, 0, largura, 30);\n" 
                    //desenha o texto indicando o valor do gráfico, na posição horizontal atual
                    "ctx.fillStyle = \"red\";\n" 
                    "ctx.fillText(resultado + \"V\", 450, 30);\n" 
                "}\n" 
            "}\n" 
            "pegouTexto = false;\n" 
        "}\n" 
    "};\n" 

"</script>\n"     
        
      );

  return conteudo; // Retorna o script
}
