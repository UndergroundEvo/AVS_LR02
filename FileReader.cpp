#include <unordered_map>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    std::cout << "Ошибка. Введите аргументы!"
              << std::endl;
    return 0;
  }

  try
  {
    while (true)
    {
      std::cout << "Введите номер пункта из списка ниже:\n"
                << " 1. Чтение выбранного файла;\n"
                << " Для выхода из программы введите любое число.\n"
                << ">> ";
      short num;
      std::cin >> num;

      short cnt = argc - 1;

      switch (num)
      {
      case 1:
      {
        std::unordered_map<int, std::vector<std::string>> map;

        for (int i = 0; i < cnt; i++)
        {
          std::ifstream file(argv[i + 1]);
          std::string line;
          std::vector<std::string> lines;

          while (std::getline(file, line))
            lines.push_back(line);

          map[i + 1] = lines;
        }

        std::cout << "Какой файл вы хотите выбрать?\n"
                  << ">> ";
        short fileNum;
        std::cin >> fileNum;

        for (const auto &line : map[fileNum])
          std::cout << line << std::endl;

        break;
      }
      default:
        return 0;
      }
    }
  }
  catch (const std::exception &err)
  {
    std::cout << err.what() << std::endl;
  }

  return 0;
}