String html_sobre()
{

  String conteudo;

  conteudo = F(
    
    "<!DOCTYPE html>\n"
      "<html lang=\"pt-br\">\n"
      
      "<head>\n"
          "<meta charset=\"UTF-8\">\n"
          "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n"
          "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
          "<title>ESP32</title>\n"
          "<link rel=\"stylesheet\" href=\"sobre.css\">\n"
      "</head>\n"
      
      "<header>\n"
          "<div class=\"logoIF\">\n"
              "<h1>Instituto Federal de São Paulo</h1>\n"
          "</div>\n"
      
          "<nav class=\"menu\">\n"
              "<div class=\"topnav\">\n"
                  "<a class=\"active\"href=\"http://192.168.4.1/\">Home</a>\n"
                  "<a href=\"http://192.168.4.1/sobre\">Sobre</a>\n"
                  "<a href=\"http://192.168.4.1/contato\">Contato</a>\n"
              "</div>\n"
          "</nav>\n"
      "</header>\n"
      
      "<body>\n"
          "<div class=\"titulo\">\n"
              "<h1>Sobre</h1>\n"
          "</div>\n"
      
          "<main class=\"conteudo\">\n"
              "<p>O osciloscópio é uma ferramenta de extrema importância para a indústria eletroeletrônica, pois ele permite"
                  "visualizar um sinal elétrico na forma de gráfico. Em outras palavras, é possível mostrar uma imagem em dois"
                  "eixos, no qual o eixo x representa o tempo e o eixo y representa os volts em amplitude. </p>\n"
      
              "<p>O objetivo desse trabalho é desenvolver um sistema de aquisição de sinais com algumas funcionalidades"
                  "similares a de um osciloscópio. Com ele será possível fazer medições em diversos tipos de ambientes (já que"
                  "sua portabilidade é fácil), sua usabilidade é bem simples (tornando-se intuitiva), e poderá ser utilizado em"
                  "escolas e universidades. Devido ao seu baixo custo, tanto alunos como professores poderão construir o seu,"
                  "para uso pessoal, em pesquisas.</p>\n"
      
              "<p>QUma das suas características notáveis é o peso que tem aproximadamente 250g, isso facilitará no seu"
                  "manuseio evitando qualquer tipo de risco ergonômico para seu portador. O método de pesquisa desse trabalho"
                  "foi totalmente experimental, onde foi possível obter resultados satisfatórios que tornaram o projeto"
                  "promissor.</p>\n"
          "</main>\n"
      "</body>\n"
      
      "<footer class=\"rodape\">\n"
          "<p>Elaborado em 2023</p>\n"
      "</footer>\n"
      "</html>\n"
      
      "<style>\n"
          /* customização aplicada a todos os elementos da página */
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
          ".corpo {\n"
              "padding: 150px 0;\n"
          "}\n"
      
          ".titulo {\n"
             "display: flex;\n"
              "justify-content: center;\n"
              "padding-top: 100px;\n"
              "color: #2c66ce;\n"
              "font-size: 20px;\n"
          "}\n"
      
          ".conteudo {\n"
              "width: 60%;\n"
              "display: flex;\n"
              "flex-direction: column;\n"
              "margin: 70px 20%;\n"
          "}\n"
      
          ".conteudo p {\n"
              "padding: 20px 0;\n"
              "font-size: 17px;\n"
              "text-align: justify;\n"
          "}\n"
      
          /* customização do rodapé */      
          ".rodape {\n"
              "width: 100%;\n"
              "display: flex;\n"
              "justify-content: center;\n"
              "align-items: center;\n"
              "height: 50px;\n"
              "background-color: #17882c;\n"
              "color: white;\n"
              "margin-top: 45px;\n"
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
          "}\n"
      
          "@media screen and (max-width: 800px) {\n"
      
              ".logoIF h1 {\n"
                  "font-size: 15px;\n"
              "}\n"
      
              ".topnav a {\n"
                  "font-size: 13px;\n"
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
          "}\n"
      "</style>\n"
     
    );

  return conteudo;

}
