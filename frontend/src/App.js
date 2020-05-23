import React from 'react';
import logo from './logo.svg';
import './App.css';
import SimpleTable from './components/Table';

import DesnseTable from './components/Analysis'
import {Button, Grid} from '@material-ui/core'

const grid = [
    [4, 3, '', ''],
    [1, 2, 3, ''],
    ['', '', 2, ''],
    [2, 1, '', ''],
];

const Solvedgrid = [
    [4, 3, 1, 2],
    [1, 2, 3, 4],
    [3, 4, 2, 1],
    [2, 1, 4, 3],
];



function App() {
  return (
    <div className="App">
        <div className="app-body">
            <h1 style={{color: '#fafafa'}}>Sodoku Solver</h1>
            <div className="line-separator"></div>
            <SimpleTable grid={grid}></SimpleTable>
            <div className="line-separator"></div>
            <Button variant="outlined" style={{color: 'white', border: '2px solid #fafafa'}}>Solve</Button>
            <div className="line-separator"></div>
            <Grid container direction="row" justify="center" alignItems="center"
>
              <Grid item xs={12} sm={6} align="center"><SimpleTable grid={Solvedgrid}></SimpleTable></Grid> 
              <Grid item xs={12} sm={6} align="center"><DesnseTable></DesnseTable></Grid>  
            </Grid>
            
        </div>
    </div>
  );
}

export default App;
