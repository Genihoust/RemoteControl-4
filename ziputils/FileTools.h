/*!
	Description : Useful File Utils.
	Author		: Ruining Song
	Date		: 2013.10.28
	Remark		: 
*/

#ifndef FILETOOLS_H
#define FILETOOLS_H

#include <Windows.h>
#include <string>

class FileTools
{
public:

	// 判断指定文件或文件夹是否存在
	static BOOL Exist(LPCWSTR lpwzFilePath);

	// 获取文件所在目录
	// eg: GetFileDir(L"C:\\Dir\\Test.exe", wzBuffer, L'\\')
	// 执行之后：wzBuffer : L"C:\\Dir"
	static VOID GetFileDir(IN LPCWSTR lpwzFile, OUT LPWSTR lpwzFilePath, WCHAR c);

	// 获取程序自身所在路径
	// 注 : 传入的 buffer 长度应为 MAX_PATH
	static VOID GetExePath(OUT LPWSTR lpwzExePath);

	// 获取程序自身所在路径
	static std::wstring GetExePathW();

	// 获取 DLL 所在路径
	static std::wstring GetDllPathW(HINSTANCE hModule);

	// 获取上一级目录
	// "C:\\123\\456" -> "C:\\123"
	static VOID GetParentDir(IN OUT LPWSTR lpwzPath);

	// 获取文件大小，如不存在则返回 -1
	static DWORD GetFileSize(LPCWSTR lpwzFile);

	// 读取文件至内存
	static BOOL ReadFileToMem(LPCWSTR lpwzFile, LPBYTE lpBuffer);

	// 将内存中数据写入至文件
	static BOOL WriteFileFromMem(LPCWSTR lpwzFile, LPBYTE lpBuffer, DWORD dwLen);

	// 由路径获取文件名
	// eg: GetFileNameWithoutPath(L"C:\\Dir\\Test.exe", wzBuffer)
	// 执行之后: wzBuffer : L"Text.exe"
	static VOID GetFileNameWithoutPath(LPCWSTR lpwzPath, LPWSTR lpwzName);

	// 创建多层目录
	static VOID CreateDirectorys(LPCWSTR lpwzDir);
};

#endif // FILETOOLS_H