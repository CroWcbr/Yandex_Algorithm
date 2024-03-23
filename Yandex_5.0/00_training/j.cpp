#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <set>

using namespace std;

struct Shape {
    size_t xPos;
    size_t yPos;
    size_t width;
    size_t height;

    Shape(const Shape& other)
        : xPos(other.xPos)
        , yPos(other.yPos)
        , width(other.width)
        , height(other.height)
    {}

    Shape(size_t x, size_t y, size_t w, size_t h)
        : xPos(x)
        , yPos(y)
        , width(w)
        , height(h)
    {}

    bool operator==(const Shape& other) const
    {
        return xPos == other.xPos && yPos == other.yPos;
    }

    bool operator<(const Shape& other) const 
    {
        if (xPos != other.xPos)
            return xPos < other.xPos;
        else if (yPos != other.yPos)
            return yPos < other.yPos;
        else if (width != other.width)
            return width < other.width;
        return height < other.height;
    }
};

enum class ImageType {
    Embedded = 0,
    Surrounded = 1,
    Floating = 2
};

struct Picture {
    size_t width;
    size_t height;
    ImageType layoutType;
    int dx;
    int dy;
    int posX;
    int posY;
};

struct Word {
    int length;
    Word() : length(0) {};
    Word(int len): length(len) {};
};

enum class ElementType {
    Word = 0,
    Image = 1,
};

struct PageElement {
    ElementType type;
    Word word;
    Picture picture;
    PageElement(ElementType t, Word w) : type(t), word(w) {};
    PageElement(ElementType t, Picture p) : type(t), picture(p) {};
};

struct PageFragment {
    size_t x;
    size_t y;
    size_t width;
    size_t height;
    bool empty;
    bool isExtended;
    PageFragment() : x(0), y(0), width(0), height(0), empty(true), isExtended(false) {}
};

class PageDocument {
private:
    set<Shape> shapeSet;
    vector<vector<PageElement>> paragraphs;
    vector<PageFragment> fragments;
    size_t pageWidth;
    size_t lineHeight;
    size_t letterWidth;

private:
    Picture parsePicture(const string& line)
    {
        Picture pic;
        string text;
        stringstream stream(line);
        while(getline(stream, text, ' '))
        {
            stringstream stream(text);
            string name, valueString;
            getline(stream, name, '=');
            getline(stream, valueString);
            if (name == "width")
                pic.width = stoi(valueString);
            else if (name == "height")
                pic.height = stoi(valueString);
            else if (name == "layout")
            {
                if (valueString == "embedded")
                    pic.layoutType = ImageType::Embedded;
                else if (valueString == "surrounded")
                    pic.layoutType = ImageType::Surrounded;
                else if (valueString ==  "floating")
                    pic.layoutType = ImageType::Floating;
            }
            else if (name == "dx")
                pic.dx = stoi(valueString);
            else if (name == "dy")
                pic.dy = stoi(valueString);
        }
        return pic;
    }

    void insertPicture(const vector<string>& data, int& i, vector<PageElement> &P, int &id)
    {
        size_t openParenthesisPos = data[id].find("(", i);
        std::string tmp = data[id].substr(openParenthesisPos);
        while (tmp.find(")") == std::string::npos)
        {
            id++;
            i = 0;
            tmp.append(" ");
            tmp.append(data[id]);
        }
        size_t closeParenthesisPos = tmp.find(")");
        // std::cout << tmp.substr(0, closeParenthesisPos) << std::endl;
        P.push_back(PageElement(ElementType::Image, parsePicture(tmp.substr(0, closeParenthesisPos))));
        i = data[id].find(")", i) + 1;
        // std::cout << i << std::endl;

        // size_t openParenthesisPos = data[id].find("(", i);
        // size_t closeParenthesisPos = data[id].find(")", i);
        // std::cout << openParenthesisPos << "\t" << closeParenthesisPos << std::endl;
        // std::cout <<  data[id].substr(openParenthesisPos, closeParenthesisPos - openParenthesisPos) << std::endl;
        // P.push_back(PageElement(ElementType::Image, parsePicture(data[id].substr(openParenthesisPos, closeParenthesisPos - openParenthesisPos))));
        // i = data[id].find(")", i) + 1;
        // std::cout << i << std::endl;
    }

    void insertWord(const std::string &line, int& i, vector<PageElement> &P)
    {
        std::string tmp;
        for (; i < line.size() && line[i] != ' '; )
            tmp.push_back(line[i++]);
        P.push_back(PageElement(ElementType::Word, Word(tmp.size())));
    }

    pair<bool, size_t> isOverlap(size_t startX, size_t finishX, size_t y)
    {
        for (auto it = shapeSet.begin(); it != shapeSet.end(); ++it)
            if ((finishX > (*it).xPos) && (startX < (*it).xPos + (*it).width) && (y >= (*it).yPos) && (y < (*it).yPos + (*it).height))
                return make_pair(true, (*it).xPos + (*it).width);
        return make_pair(false, 0);
    }

    pair<bool, size_t> checkInsert(const PageFragment& F, size_t elementWidth, size_t c)
    {
        size_t startX = F.x + F.width;
        size_t finishX = startX + elementWidth;
        if (!F.empty)
            finishX += c;
        return make_pair(((finishX <= pageWidth) && !isOverlap(startX, finishX, F.y).first), finishX - F.x);
    }

    void findFragment(PageFragment& F, size_t w, bool useDelimeter = false)
    {
        size_t startX = F.x + F.width;
        size_t finishX = startX + w;
        size_t y = F.y;
        size_t startY = y;
        if (useDelimeter && F.isExtended)
            finishX += letterWidth;
        if (finishX > pageWidth)
        {
            y += F.height > lineHeight ? F.height : lineHeight;
            startX = 0;
            finishX = w;
            F.height = lineHeight;
            F.isExtended = false;
        }
        auto result = isOverlap(startX, finishX, y);
        while(result.first)
        {
            startX = result.second;
            finishX = startX + w;
            if (finishX > pageWidth)
            {
                y += F.height > lineHeight ? F.height : lineHeight;
                startX = 0;
                finishX = w;
                F.height = lineHeight;
                F.isExtended = false;
            }
            result = isOverlap(startX, finishX, y);
        }
        F.x = startX;
        F.y = y;
        if (startY != y)
            F.height = lineHeight;
        F.width = 0;
        F.empty = true;
        F.isExtended = false;
        vector<Shape> del;
        for (auto it = shapeSet.begin(); it != shapeSet.end(); ++it)
            if ((*it).yPos + (*it).height < y)
                del.push_back((*it));
        for(const auto& s: del)
            shapeSet.erase(s);
    }

    void  doWord(PageElement& element, PageFragment& F)
    {
        int wordWidth = element.word.length * letterWidth;
        auto result = checkInsert(F, wordWidth, letterWidth);
        if (result.first)
            F.width = result.second;
        else
        {
            if (F.width != 0)
                fragments.push_back(F);
            findFragment(F, wordWidth, true);
            F.width = wordWidth;
        }
        F.empty = false;
        F.isExtended = true;
    }

    void doEmbedded(Picture& pic, PageFragment& F)
    {
        auto result = checkInsert(F, pic.width, letterWidth);
        size_t width;
        if (result.first)
            width = result.second;
        else
        {
            if (F.width != 0)
                fragments.push_back(F);
            width = pic.width;
            findFragment(F, width, true);
        }
        F.width = width;
        if (pic.height > F.height)
            F.height = pic.height;
        pic.posX = F.x + F.width - pic.width;
        pic.posY = F.y;
        F.empty = false;
        F.isExtended = true;
    }

    void doSurrounded(Picture& pic, PageFragment& F)
    {
        fragments.push_back(F);
        F.x += F.width;
        F.width = 0;
        F.empty = true;
        F.isExtended = false;
        auto result = checkInsert(F, pic.width, 0);
        if (result.first)
        {
            shapeSet.insert(Shape(F.x + F.width, F.y, pic.width, pic.height));
            F.width = result.second;
        }
        else
        {
            if (F.width != 0) {
                fragments.push_back(F);
            }
            findFragment(F, pic.width);
            shapeSet.insert(Shape(F.x + F.width, F.y, pic.width, pic.height));
            F.width = pic.width;
        }
        pic.posX = F.x + F.width - pic.width;
        pic.posY = F.y;
        fragments.push_back(F);
        F.x += F.width;
        F.width = 0;
        F.empty = true;
        F.isExtended = false;
        F.isExtended = false;
    }

    void doFloating(Picture& pic, const PageFragment& F, bool isFloating)
    {
        static Picture lastPicture;
        int x, y;
        if (isFloating)
        {
            x = lastPicture.posX + lastPicture.width;
            y = lastPicture.posY;
        }
        else
        {
            x = F.x + F.width;
            y = F.y;
        }
        x += pic.dx;
        y += pic.dy;
        if (x < 0)
            x = 0;
        else if (x + pic.width > pageWidth)
            x = pageWidth - pic.width;
        pic.posX = x;
        pic.posY = y;
        lastPicture = pic;
    }

public:
    PageDocument(std::string inputName)
    {
        ifstream input(inputName);
        input >> pageWidth >> lineHeight >> letterWidth;
        input.ignore();
        string line;
        vector<string> data;
        while (getline(input, line))
        {
            if (input.eof())
                break;
            data.push_back(line);
        }
        input.close();

        bool image = false;
        vector<PageElement> P;
        // for (auto line : data)
        for (int id = 0; id < data.size(); ++id)
        {
            if (data[id].find_first_not_of(' ') == string::npos || data[id].empty())
            {
                paragraphs.push_back(P);
                P.clear();
                continue;
            }
            for (int i = 0; i < data[id].size();)
            {
                if (data[id][i] == ' ')
                {
                    ++i;
                    continue;
                }
                else if (data[id][i] == '(')
                    insertPicture(data, i, P, id);
                else
                    insertWord(data[id], i, P);
            }
        }
        paragraphs.push_back(P);
        data.clear();
    }

    void makeDecisions()
    {
        bool isFloating;
        PageFragment F;
        F.height = lineHeight;
        for (size_t i = 0; i < paragraphs.size(); ++i)
        {
            for (size_t j = 0; j < paragraphs[i].size(); ++j)
            {
                if (paragraphs[i][j].type == ElementType::Word)
                {
                    doWord(paragraphs[i][j], F);
                    isFloating = false;
                }
                else if (paragraphs[i][j].type == ElementType::Image)
                {
                    if ( paragraphs[i][j].picture.layoutType == ImageType::Embedded)
                    {
                        doEmbedded(paragraphs[i][j].picture, F);
                        isFloating = false;
                    }
                    else if (paragraphs[i][j].picture.layoutType == ImageType::Surrounded)
                    {
                        doSurrounded(paragraphs[i][j].picture, F);
                        isFloating = false;
                    }
                    else if (paragraphs[i][j].picture.layoutType == ImageType::Floating)
                    {
                        doFloating(paragraphs[i][j].picture, F, isFloating);
                        isFloating = true;
                    }
                }
            }
            fragments.push_back(F);
            F.x = 0;
            F.y += F.height;
            F.width = 0;
            F.height = lineHeight;
            F.empty = true;
            isFloating = false;
        }
    }

    void printResult(ostream& output)
    {
        bool first = true;
        for (size_t i = 0; i < paragraphs.size(); ++i)
        {
            for (size_t j = 0; j < paragraphs.at(i).size(); ++j)
            {
                const PageElement& element = paragraphs.at(i).at(j);
                if (element.type != ElementType::Image)
                    continue;
                else if (!first)
                    output << endl;
                output << element.picture.posX << " " << element.picture.posY;
                first = false;
            }
        }
    }
};

int main()
{
    PageDocument document("input.txt");
    document.makeDecisions();
    document.printResult(cout);
}
