use std::env; //collect
use std::process;
use minigrep::*;


fn main() {
    let args:Vec<String> = env::args().collect();//无法处理非法unicode字符


    let config = Config::new(&args).unwrap_or_else(|err|{
        eprintln!("parsing fails:{}",err);//标准错误
        process::exit(1)
    });
    if let Err(e) = run(config){
        eprintln!("error:{}",e);
        process::exit(1)
    }   
} 