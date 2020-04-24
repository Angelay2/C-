#pragma once
// namespace 命名空间名称 {}
// m
namespace head1{
	int global = 100;
	// 嵌套定义
	namespace internal{
		int val = 10;
	}
}
// 分段定义, 最终可以合在一个空间下使用 相当于是一个
namespace head1{
	int val2;
}