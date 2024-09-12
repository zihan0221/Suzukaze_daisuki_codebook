import sys, os

# 設定大數運算最大位數, 複雜度需考慮運算位數
sys.set_int_max_str_digits(100000)

# 開讀檔
if(os.path.exists('input_file.txt')):
    sys.stdin = open("input_file.txt","r")
    sys.stdout = open("output_file.txt","w")