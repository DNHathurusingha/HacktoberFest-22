from flask import Flask, render_template
from datetime import datetime
server = Flask(__name__)

@server.route('/mydetail')
def mydetail():
    current_time = datetime.now()
    return render_template('mydetail.html',current_time=current_time)

if __name__==('__main__'):
    server.run(debug=True)
