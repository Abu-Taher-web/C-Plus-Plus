/**
 * @file shuffleCards.cpp
 * @author Anna LaValle
 * @date Created: Spring 2025
 */

//TODO you will need to modify this function (called from main.cpp)
void shuffleCards(){

	const std::string OUTPUT_FILE = "shuffle.png";
    std::string INPUT_FILE = "Images/";
    PNG out("Images/canvas.png");
    int WIDTH = out.width();
    int HEIGHT = out.height();
    const int num_cards = 10;
    
    Canvas outputCanvas;
    List<PNGLayer> list;

    // Load all 10 cards into the list
    for (int i = 1; i <= num_cards; i++) {
        std::string filename = std::to_string(i) + ".png";
        PNGLayer p(WIDTH, HEIGHT, Vector2(0.0, 0.0), Vector2(1.0, 1.0), 
                 RGBAPixel(255,255,255,255), std::to_string(i));
        p.readFromFile(INPUT_FILE + filename);
        list.insertBack(p);
    }

    // Shuffle the list
    list.shuffle();

    // Get the shuffled cards using iterator or public methods
    // Method 1: Using iterator (if available)
    for (auto it = list.begin(); it != list.end(); ++it) {
        static int index = 0;
        PNGLayer& p = *it;
        p.SetPosition(Vector2(
            WIDTH/100 + (WIDTH-WIDTH/9)/num_cards * index, 
            HEIGHT/4
        ));
        outputCanvas.Add(p);
        index++;
    }

    // OR Method 2: Using a temporary vector (if iterator isn't available)
    /*
    std::vector<PNGLayer> temp;
    while (!list.isEmpty()) {
        temp.push_back(list.front());
        list.removeFront();
    }
    for (int index = 0; index < temp.size(); index++) {
        temp[index].SetPosition(Vector2(
            WIDTH/100 + (WIDTH-WIDTH/9)/num_cards * index, 
            HEIGHT/4
        ));
        outputCanvas.Add(temp[index]);
    }
    */

    // Draw and save the final image
    outputCanvas.draw(out);
    out.writeToFile(OUTPUT_FILE);
}
