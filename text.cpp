#include "text.h"
#include "input.h"

Text::Text(Text * target)
{
	data = (*target).get_data();
}

Text::~Text()
{
	data.clear();
}

void Text::input()
{
	data.clear();
	std::cout << "Введите текст (для завершения ввода нажмите CTRL+D и ENTER):" << std::endl << std::endl;
	std::string text;
	std::getline(std::cin, text, static_cast<char>(4));
	std::stringstream ss(text);
	std::string tmp;
	while (true)
	{
		ss >> tmp;
		if (!ss.eof())
			data.push_back(tmp);
		else
			break;
	}
}

void Text::load(std::string filename)
{
	data.clear();
	std::ifstream out{ filename.c_str() };
	std::error_code ec;
	if (!std::filesystem::is_regular_file(filename, ec))
	{
		std::cout << "\tИмя зарезервировано системой!" << std::endl;
		return;
	}
	else if (!out.is_open())
	{
		std::cout << "\tОшибка при открытии файла!" << std::endl;
		return;
	}
	std::string tmp;
	while (true)
	{
		out >> tmp;
		if (!out.eof())
			data.push_back(tmp);
		else
			break;
	}
	std::cout << "\tЗагружено" << std::endl << std::endl;
}


void Text::print()
{
	for (size_t i = 0; i < data.size(); i++)
		std::cout << data[i] << " ";
	std::cout << std::endl << std::endl;
}

void Text::analyze()
{
	std::vector <std::string> keys;
	std::vector <std::vector <size_t>> values;
	std::string key;
	size_t value = keys.size();

	if (data.size() == 0)
	{
		std::cout << "Введённый текст не содержит слов" << std::endl << std::endl;
		return;
	}

	for (size_t i = 1; i < data.size() - 1; i++)
	{
		value = keys.size();
		key = data[i - 1] + " " + data[i + 1];
		for (size_t o = 0; o < keys.size(); o++)
			if (key == keys[o])
			{
				value = o;
				break;
			}
		if (value == keys.size())
		{
			keys.push_back(key);
			values.push_back(std::vector <size_t>());
		}
		values[value].push_back(i);
	}

	std::vector <int> indicies;
	Text editable_text;

	for (size_t i = 0; i < keys.size(); i++)
		if (values[i].size() > 1)
		{

			for (size_t o = 0; o < pow(values[i].size(), values[i].size()); o++)
			{
				indicies = get_in_other(static_cast<int>(o), static_cast<int>(values[i].size()));
				editable_text = Text(this);
				editable_text.replace(values[i], indicies);
				editable_text.print();
				indicies.clear();
			}
		}

	if (keys.size() == 0)
		std::cout << "Недостаточно подстрок для анализа" << std::endl << std::endl;
}

bool Text::empty()
{
	return data.size() == 0;
}

std::vector <std::string> Text::get_data()
{
	std::vector <std::string> data_copy = data;
	return data_copy;
}

void Text::replace(std::vector <size_t> values, std::vector <int> indicies)
{
	std::vector <std::string> words;
	for (size_t i = 0; i < indicies.size(); i++)
		words.push_back(data[values[i]]);
	for (size_t i = 0; i < values.size(); i++)
		data[values[i]] = words[indicies[i]];
	words.clear();
}

std::vector <int> get_in_other(int iter, int n)
{
	std::vector <int> v;
	for (int i = 0; i < n; i++)
	{
		v.insert(v.begin(), iter % n);
		iter /= n;
	}
	return v;
}
