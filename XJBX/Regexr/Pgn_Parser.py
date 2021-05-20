import re
# import pandas as pd
# import matplotlib.pyplot as plt
# import numpy as np
# import os
# import shutil


class ParsePgn:
    # def __init__(self,filepath,outfilepath):
    #     res = self.deal_pgn(filepath,outfilepath)
    #     # 生成1w1b的文件
    #     self.generate_sub_files(res)
    #     # # plot
    #     self.plot_top_ten_moves(res)

    def pgnParse(self,filepath, outputfilepath):
        with open(filepath,mode='r',encoding='utf-8') as fin:
            rawdata = fin.readlines()
        game_data = []
        cur = []
        for lines in rawdata:
            lines.replace('\n', ' ')
            if lines.startswith('[') or lines.startswith('\n'):
                continue
            match = re.match(r'([\w\W]+)  [0-1]\/?[0-2]?\-[0-1]\/?[0-2]?', lines)
            if match:
                cur.append(match.group(1).replace('\n', ' '))
                game_data.append("".join(cur))
                cur.clear()
            else:
                cur.append(lines.replace('\n', ' '))
        try:
            fout = open(outputfilepath, mode='w', encoding='utf-8')
        except IOError:
            print("cant creat game_string")
        else:
            print("open sucess")
            fout.write("\n".join(game_data))
        return game_data

    # def generate_df_counts(self,game_data):
    #     first_moves_container = [{}, {}]
    #     for _, line in enumerate(game_data, 1):
    #         first_moves = re.split(r'\s\d\.', line, maxsplit=1)[0]
    #         first_moves = first_moves.strip()
    #         first_moves = re.sub(r'\d\.', '', first_moves).split(' ')
    #         for i, each_move in enumerate(first_moves):
    #             if each_move not in first_moves_container[i]:
    #                 first_moves_container[i][each_move] = 0
    #             first_moves_container[i][each_move] += 1
    #     return pd.DataFrame(first_moves_container[0].items(), columns=['move', 'move_count']), pd.DataFrame(first_moves_container[1].items(), columns=['move', 'move_count'])


    # def generate_sub_files(self,game_data):
    #     sub_folder = 'sub_files_dir'
    #     # 创建subfolder
    #     try:
    #         os.makedirs(sub_folder)
    #     except FileExistsError:
    #         print("sub_files_dir now exists")
    #     for game_count, line in enumerate(game_data, 1):
    #         # 输出
    #         files_out = [open(os.path.join(sub_folder, '{0}w'.format(game_count)), encoding='utf-8', mode='w'),
    #                      open(os.path.join(sub_folder, '{0}b'.format(game_count)), encoding='utf-8', mode='w')]
    #         # 拿到每一步
    #         for move_count, each_move in enumerate(re.split(r'\d+\.', line)):
    #             each_move = each_move.strip()
    #             if len(each_move) > 0:
    #                 for i, move_step in enumerate(each_move.replace('  ', ' ').split(' ')):
    #                     try:
    #                         files_out[i].write('{move_count}.{move_step}\n'.format(move_count = move_count,move_step=move_step))
    #                     except IndexError:
    #                         print("out range")
    #         for each in files_out:
    #             each.close()
    #     print("generating sub_file sucess")

    # def plot_top_ten_moves(self,game_data):
    #     w_count, b_count = self.generate_df_counts(game_data)
    #     w_count_top10 = w_count.nlargest(10, 'move_count')
    #     b_count_top10 = b_count.nlargest(10, 'move_count')
    #     width = 0.4
    #     fig, ax = plt.subplots()
    #     ax.bar(np.arange(w_count_top10.shape[0]) - width / 2, w_count_top10.move_count.values, width,
    #                 label='white')
    #     ax.bar(np.arange(b_count_top10.shape[0]) + width / 2, b_count_top10.move_count.values, width,
    #                 label='black')
    #     ax.legend()
    #     w_labels = [f"{each[0]}: {each[1]}" for each in w_count_top10.values]
    #     for rect, label in zip(ax.patches[: w_count_top10.shape[0]], w_labels):
    #         height = rect.get_height()
    #         ax.text(rect.get_x() + rect.get_width() / 4, height + 10, label, rotation=90, size=9)
    #     fig.savefig('top_ten_moves.png')
    #     print("plot success")


# if __name__ =="__main__":
#     pgn_file = "chess_game.pgn"
#     output_file = "game_string.txt"
#     rawout = pgn_parse(pgn_file,output_file)
#     try:
#         shutil.rmtree('./sub_files_dir')
#     except:
#         print("blalala")
#     else:
#         print("folder has been delete")