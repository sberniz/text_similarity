# main FastAPI
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
import uvicorn
from app.functions import similarity
from pydantic import BaseModel,Field,validator
app = FastAPI(title="Similarity Comparison",
description="Compares between different Text",
version="0.1",
docs_url='/')
#Class for text body
class Texts(BaseModel):
    '''Requests Data from two different texts'''
    text1: str = Field(...,example='Hello everyone')
    text2: str = Field(...,example='Hello everyone')
@app.post('/compare')
def compare(texts: Texts):
    """ ### USAGE: 
         - /compare 
         - POST request with body of two strings (text1,text2)
         - Return json object with similarity: value 
        ### Try it directly here
         - Click 'Try it out'
         - replace the sample stringss. 
         - click execute 
         """
    similar = similarity(texts.text1,texts.text2)

    return {
        'similarity':similar
    }

app.add_middleware(
    CORSMiddleware,
    allow_origins=['*'],
    allow_credentials=True,
    allow_methods=['*'],
    allow_headers=['*'],
)
if __name__ == '__main__':
    uvicorn.run(app)