syntax on
set nocompatible              " be iMproved, required
set backspace=2
set foldmethod=indent
set foldlevel=99
"show the matching part of the pair for [] {} and ()
set showmatch
set autoindent
set cindent
set shiftwidth=2
set expandtab
"filetype off                  " required
"set number
" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
Plugin 'Valloric/YouCompleteMe'
"Plugin 'tmhedberg/SimpylFold'
Plugin 'scrooloose/nerdtree'
Plugin 'scrooloose/syntastic'
Plugin 'derekwyatt/vim-scala'
Plugin 'lervag/vimtex'
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
"let g:ycm_key_list_select_completion=[]
"let g:ycm_key_list_previous_completion=[]
let g:SimpylFold_docstring_preview=1
nnoremap <space> za
let g:ycm_autoclose_preview_window_after_completion=1
"map <leader>g	:YcmCompleter GoToDefinitionElseDeclaration<CR>
"let NERDTreeIgnore=['\.pyc$','\~$']
let g:ycm_global_ycm_extra_conf = '~/.vim/.ycm_extra_conf.py'
let g:ycm_python_binary_path="/data/Apps/anaconda3/bin/python"
let g:ycm_server_keep_logfiles=1
let g:ycm_server_log_level='debug'
filetype on
let g:syntastic_check_on_open = 1
let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_wq = 0
let g:syntastic_quiet_messages={'level':'warnings'}
inoremap <C-s> <esc>:w<enter>
nnoremap  :YcmCompleter GoToDeclaration:sb1 :wincmd w  :resize 10 
"enable all Python syntax hightlighting features
let python_highlight_all=1
set omnifunc=syntaxcomplete#Complete
