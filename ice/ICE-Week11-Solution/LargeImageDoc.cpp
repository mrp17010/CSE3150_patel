// The following code works on small data, but not on large data
#include <vector>
#include <set>
#include <map>
#include <string>

// Large document
class LargeImageDoc
{
public:
    // <int, string>: the page where the image is at and the filename to load the image
    // LargeImageDoc(const std::map<int, std::string> &listImageInfo) : numTicks(0)
    // {
    //     for (auto it = listImageInfo.begin(); it != listImageInfo.end(); ++it)
    //     {
    //         LoadImage(it->first, it->second);
    //     }
    // }
    explicit LargeImageDoc(const std::map<int, std::string> &listImageInfo)
        : imageInfo(listImageInfo), numTicks(0) {}

    void Show(int page)
    {
        // do nothing for now
        // Check if the image for this page needs to be loaded
        if (imageInfo.find(page) != imageInfo.end() && loadedImages.find(page) == loadedImages.end())
        {
            LoadImage(page, imageInfo[page]);
            loadedImages.insert(page); // Mark this page's image as loaded
        }
        // Display the page (implementation not shown)
    }

private:
    // don't change this function
    void LoadImage(int page, const std::string &fileNameImage)
    {
        for (int i = 0; i < 1000000; ++i)
        {
            ++numTicks;
        }
    }

    std::map<int, std::string> imageInfo; // Map of page number to image file name
    std::set<int> loadedImages;           // Set of pages whose images have been loaded
    int numTicks;
};
