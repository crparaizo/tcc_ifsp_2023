String html_contato()
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
          "<link rel=\"stylesheet\" href=\"contato.css\">\n"
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
              "<h1>Contato</h1>\n"
          "</div>\n"
          "<main class=\"conteudo\">\n"
              "<div>\n"
                  "<h2>Alunos</h2>\n"
                  "<ul>\n"
                      "<a href=\"https://www.linkedin.com/in/bruno-vinicius-81a3181b1/\">\n"
                          "<li>Bruno Vinicius Lima da Silva</li>\n"
                      "</a>\n"
                      "<a href=\"https://www.linkedin.com/in/crparaizo/\">\n"
                          "<li>Cândida Rosa Paraizo</li>\n"
                      "</a>\n"
                      "<a href=\"https://www.linkedin.com/in/marcos-knijnik-70244748/\">\n"
                         " <li>Marcos Judensnaider Knijnik</li>\n"
                      "</a>\n"
                  "</ul>\n"
              "</div>\n"
              "<div>\n"
                  "<h2>Professores</h2>\n"
                  "<ul>\n"
                      "<a href=\"#\">\n"
                          "<li>Gustavo Neves Margarido</li>\n"
                      "</a>\n"
                      "<a href=\"#\">\n"
                          "<li>Rodrigo Rech</li>\n"
                      "</a>\n"
                      "<a href=\"#\">\n"
                          "<li>Tarsício Fernandes Leão</li>\n"
                      "</a>\n"
                  "</ul>\n"
              "</div>\n"
              "<div>\n"
                  "<h2>Instituição</h2>\n"
                  "<a href=\"https://www.ifsp.edu.br/\">\n"
                      "<li>Instituto Federal de São Paulo</li>\n"
                  "</a>\n"
              "</div>\n"
              "<div>\n"
                  "<h2>Links do projeto</h2>\n"
                  "<ul>\n"
                      "<a href=\"https://github.com/crparaizo/tcc_ifsp_2023\">\n"
                          "<li>Repositório Github</li>\n"
                      "</a>\n"
      
                      "<a href=\"https://github.com/vthayashi/labhome\">\n"
                          "<li>Projeto base</li>\n"
                      "</a>\n"
                  "</ul>\n"
              "</div>\n"
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
      
          ".titulo {\n"
              "display: flex;\n"
              "justify-content: center;\n"
              "padding-top: 40px;\n"
              "color: #2c66ce;\n"
              "margin: 1em 0;\n"
          "}\n"
      
          ".conteudo {\n"
              "display: flex;\n"
              "align-items: center;\n"
              "justify-content: center;\n"
              "flex-direction: column;\n"
          "}\n"
      
          ".conteudo div {\n"
              "align-items: center;\n"
              "display: flex;\n"
              "flex-direction: column;\n"
              "margin: 15px;\n"
          "}\n"
      
          ".conteudo div h2 {\n"
              "font-size: 17px;\n"             
          "}\n"
      
          ".conteudo div a {\n"
              "text-decoration: none;\n"
              "list-style-type: none;\n"
          "}\n"
      
          ".conteudo div a li {\n"
              "padding-top: 13px;\n"
              "justify-content: center;\n"
              "display: flex;\n"
          "}\n"
      
          ".conteudo div a li:hover {\n"
              "text-decoration: underline;\n"
              "color: red;\n"
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
              "margin-top: 30px;\n"
          "}\n"
      
          /* Aplicando responsividade de acordo com tamanho da tela */
      
          "@media screen and (max-width: 1300px) {\n"
      
              ".logoIF h1 {\n"
                  "font-size: 25px;\n"
              "}\n"
          "}\n"
      
         " @media screen and (max-width: 1100px) {\n"
      
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
