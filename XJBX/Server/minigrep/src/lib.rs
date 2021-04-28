use std::error::Error;
use std::fs;
use std::env;

pub fn run(config:Config)->Result<(),Box<dyn Error>>{
    let content = fs::read_to_string(config.filename)?;
    let results = if config.case_sensitive{
        search(&config.query, &content)
    }else{
        search_insensitive(&config.query, &content)
    };
    for line in results{
        println!("{}",&line);
    }
    Ok(())
}

pub struct Config{
    pub query:String,
    pub filename:String,
    pub case_sensitive:bool,
}

impl  Config {
    pub fn new(args:&[String])->Result<Config,&'static str>{
        if args.len() < 3{
           return Err("not enough args");
        }
        let  query = args[1].clone();
        let filename = args[2].clone();
        let case_sensitive = env::var("CASE_INSENSITIVE").is_err();//环境变量
        Ok(Config{query,filename,case_sensitive})
    }
}


pub fn search<'a> (query:&str,content:&'a str)->Vec<&'a str>{
    let mut results = Vec::new();
    for line in content.lines(){
        if line.contains(query){
            results.push(line);
        }
    }
    results
}

pub fn search_insensitive<'a> (query:&str,content:&'a str)->Vec<&'a str>{
    let mut results = Vec::new();
    let query = query.to_lowercase();
    for line in content.lines(){
        if line.to_lowercase().contains(&query){
            results.push(line);
        }
    }
    results
}


#[cfg(test)]
mod tests  {
    use super::*;

    #[test]
    fn case_sensitive() {
        let query = "duct";
        let contents = "\
Rust:
safe,fase,product
Pick threee
Duct tape";
        assert_eq!(vec!["safe,fase,product"],search(query,contents))
    }

    #[test]
    fn case_insensitive(){
        let query = "rUsT";
        let contents = "\
Rust:
safe fast,productive
Trust me.";
        assert_eq!(vec!["Rust:","Trust me."],search_insensitive(query, contents))
    }
}