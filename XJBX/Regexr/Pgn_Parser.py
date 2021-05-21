import re
# import pandas as pd
# import matplotlib.pyplot as plt
# import numpy as np
# import os
# import shutil

class pgn_parse:
    # def __init__(self,filepath,outfilepath):
    #     res = self.deal_pgn(filepath,outfilepath)
    #     # 生成1w1b的文件
    #     self.generate_sub_files(res)
    #     # # plot
    #     self.plot_top_ten_moves(res)

    def deal_pgn(self,filepath, outputfilepath):
        try:
            with open(filepath,mode='r',encoding='utf-8') as fin:
                rawdata = fin.readlines()
        except:
            print("file not found or encoding not right")
        else:
            game_data = []
            cur = []
            for lines in rawdata:
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
                fout.write("\n".join(game_data))
                print("game_string gen sucess")
            return game_data

#     def generate_df_counts(self,game_data):
#         first_moves_container = [{}, {}]
#         for _, line in enumerate(game_data, 1):
#             firstMoves = re.split(r'\s\d\.', line, maxsplit=1)[0]
#             firstMoves = firstMoves.strip()
#             firstMoves = re.sub(r'\d\.', '', firstMoves).split(' ')
#             for i, each_move in enumerate(firstMoves):
#                 if each_move not in first_moves_container[i]:
#                     first_moves_container[i][each_move] = 0
#                 first_moves_container[i][each_move] += 1
#         return pd.DataFrame(first_moves_container[0].items(), columns=['move', 'move_count']), pd.DataFrame(first_moves_container[1].items(), columns=['move', 'move_count'])


#     def generate_sub_files(self,game_data):
#         if not game_data:
#             print("game_data is none")
#             return
#         sub_folder = 'sub_files_dir'
#         # 创建subfolder
#         try:
#             os.makedirs(sub_folder)
#         except FileExistsError:
#             print("sub_files_dir now exists")
#         # 每一棋局的棋盘
#         for game_count, line in enumerate(game_data, 1):
#             # 输出
#             files_out = [open(os.path.join(sub_folder, '{0}w'.format(game_count)), encoding='utf-8', mode='w'),
#                          open(os.path.join(sub_folder, '{0}b'.format(game_count)), encoding='utf-8', mode='w')]
#             # 拿到每一步
#             for move_count, each_move in enumerate(re.split(r'\d+\.', line)):
#                 each_move = each_move.strip()
#                 if len(each_move) > 0:
#                     for i, move_step in enumerate(each_move.replace('  ', ' ').split(' ')):
#                         try:
#                             files_out[i].write('{move_count}.{move_step}\n'.format(move_count=move_count,move_step=move_step))
#                         except IndexError:
#                             print("out range")
#             # 关闭缓冲区
#             for fd in files_out:
#                 fd.close()
#         print("generating sub_file sucess")

#     def plot_top_ten_moves(self,game_data):
#         if game_data is None:
#             return
#         w_count, b_count = self.generate_df_counts(game_data)
#         all_move = pd.concat([w_count,b_count],ignore_index=True)
#         count_10 = all_move.nlargest(10,'move_count')
#         w_moves,b_moves = [],[]
#         w_labels,b_labels = [],[]
#         cnt = 0
#         for i in count_10.index:
#             if i < w_count.shape[0]:
#                 w_moves.append(count_10.loc[i].move_count)
#                 w_labels.append(cnt)
#             else:
#                 b_moves.append(count_10.loc[i].move_count)
#                 b_labels.append(cnt)
#             cnt += 1
#         x_labels = count_10['move'].values
#         fig, ax = plt.subplots()
#         plt.title('Top 10 first moves')
#         rectw = ax.bar(w_labels,w_moves,label='whight')
#         rectb = ax.bar(b_labels,b_moves,label='black')
#         ax.set_ylabel('Move_count')
#         ax.set_xlabel('top_move')
#         ax.set_xticks(np.arange(count_10.shape[0]))
#         ax.set_xticklabels(x_labels)
#         ax.legend()
#         for rect, label in zip(rectw.patches[: len(w_moves)], w_moves):
#             height = rect.get_height()
#             ax.text(rect.get_x() + 0.1, height + 10, label, size=9)

#         for rect,label in zip(rectb.patches[:len(b_moves)],b_moves):
#             height = rect.get_height()
#             ax.text(rect.get_x() + 0.1 , height + 10, label, size=9)
#         fig.savefig('top_ten_moves.png')
#         print("plot success")


# if __name__ =="__main__":
#     pgn_file = "chess_game.pgn"
#     output_file = "game_string.txt"
#     pgn_parse(pgn_file,output_file)
#     needDeletSubFolder = False
#     if needDeletSubFolder:
#         try:
#             shutil.rmtree('./sub_files_dir')
#         except:
#             print("cant delete subFolder")
#         else:
#             print("folder has been delete")
