#include "lexical_analysis.h"
#include "grammar.h"
#include "grammatical_analysis.h"
#include "Generate_asm.h"

int main() {
	string t;
	cout << endl;
	//类C编译器设计与实现
	cout << "                  　Class C compiler design and implementation" << endl;
	cout << "                                  1956209   趙 敏行" << endl;
	cout << endl;
	//默认使用 ./test_files/grammar.txt 文件中的语法进行语法分析
	cout << "The default is to use ./test_files/grammar.txt file for syntax analysis" << endl;
	cout << endl;
	//正在读入 ./test_files/grammar.txt 文件中的语法...
	cout << "Reading in ./test_files/grammar.txt file for syntax..." << endl;
	LR1 LR1("./test_files/grammar.txt");
	cout << endl;
	cout << endl;

	while (1) {
		try {
			//请输入待编译程序所在的文件名（您可以直接输入 ./test_files/test_code.cpp ）
			cout << "Please enter the name of the file where the program is to be compiled (you can just type ./test_files/test_code.cpp)" << endl;

			string test_code_file_path;
			cin >> test_code_file_path;
			cout << endl;
			//正在进行词法分析...
			cout << "Lexical analysis is underway..." << endl;
			lexical_analysis lexicalAnalysis(test_code_file_path);
			lexicalAnalysis.print_token_stream("./test_files/lexical_analysis.txt");
			cout << endl;
			//词法分析已完成....\n\n词法分析结果已输出到./test_files/lexical_analysis.txt中
			cout << "Lexical analysis has been completed .... The results of \n\n lexical analysis have been output to\n ./test_files/lexical_analysis.txt" << endl;
			cout << endl;
			//您是否希望将词法分析结果输出到屏幕？（y / n）
			cout << "Do you want to output the lexical analysis results to the screen? (y/n)" << endl;

			cin >> t;
			if (t == "y") {
				fstream lexical_analysis_result("./test_files/lexical_analysis.txt", ios::in);
				string tmp;
				while (!lexical_analysis_result.eof()) {
					getline(lexical_analysis_result, tmp);
					cout << tmp << endl;;
				}
				lexical_analysis_result.close();
			}

			cout << endl;
			//正在进行语法分析和语义分析...
			cout << "Syntactic analysis and semantic analysis are underway..." << endl;
			cout << endl;
			LR1.parser(lexicalAnalysis.get_token_stream(), "./test_files/grammatical_analysis.txt");
			//语法分析和语义分析已完成....\n\n语法分析结果已输出到 ./test_files/grammatical_analysis.txt 中
			cout << "Syntax analysis and semantic analysis have been completed .... The results of \n\n grammatical analysis have been output to \n./test_files/grammatical_analysis.txt" << endl;
			cout << endl;
			//语义分析结果已输出到 ./test_files/quaternary.txt 中
			cout << "The semantic analysis results have been output to ./test_files/quaternary.txt" << endl;
			cout << endl;
			//您是否希望将语法分析结果输出到屏幕？（y/n）
			cout << "Do you want to output the syntax analysis results to the screen? (y/n)" << endl;

			cin >> t;
			if (t == "y") {
				fstream LR1_analysis_result("./test_files/grammatical_analysis.txt", ios::in);
				string tmp;
				while (!LR1_analysis_result.eof()) {
					getline(LR1_analysis_result, tmp);
					cout << tmp << endl;;
				}
				LR1_analysis_result.close();
			}

			cout << endl;
			cout << "Do you want the semantic analysis results to be output to the screen? (y/n)" << endl;

			cin >> t;
			if (t == "y") {
				fstream symantic_analysis_result("./test_files/quaternary.txt", ios::in);
				string tmp;
				while (!symantic_analysis_result.eof()) {
					getline(symantic_analysis_result, tmp);
					cout << tmp << endl;;
				}
				symantic_analysis_result.close();
			}

			cout << endl;
			//正在进行目标代码生成...
			cout << "Target code generation in progress..." << endl;
			Generate_asm generate_asm("./test_files/mips.asm", LR1.symantic_analysis.quaternary);
			generate_asm.parse();
			cout << endl;
			//目标代码生成已完成....\n\n目标代码生成结果已输出到 ./test_files/mips.asm 中
			cout << "Target code generation has been completed .... The result of \n\n target code generation has been output to\n ./test_files/mips.asm" << endl;
			cout << endl;
			//您是否希望将目标代码结果输出到屏幕？（y/n）
			cout << "Do you want the target code results to be output to the screen? (y/n)" << endl;

			cin >> t;
			if (t == "y") {
				fstream generate_asm_result("./test_files/mips.asm", ios::in);
				string tmp;
				while (!generate_asm_result.eof()) {
					getline(generate_asm_result, tmp);
					cout << tmp << endl;
				}
				generate_asm_result.close();
			}

			cout << endl;

		}
		catch (int e) {
			cout << "【Error Code】" << e << endl;
		}//是否还有其他文件需要编译(y/n)
		cout << "Are there any other files to compile (y/n)" << endl;
		cin >> t;
		if (t != "y") {
			break;

		}
	}
	return 0;
}

